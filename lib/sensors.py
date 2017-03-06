"""@package docstring
Sensor objects store information & provide methods for a given hardware sensor.

For each hardware sensor connected to the HUD system a Sensor object must be instantiated.
This object is used to handle all actions pertaining to the hardware sensor.

From the point of view of the microcontroller running the HUD system code, a hardware sensor
is simply a voltage on one of the ADC channels. For the voltage to be converted into meaningful
data, it is necessary to keep track of information about the hardware sensor and tie that
information to the value read on the given ADC channels. For example, in order for a voltage to
represent a given physical parameter, it is necessary to know the conversion formula from volts
to the desired physical units. It is assumed that the conversion formula is linear.

An instantiated Sensor object keeps track of all necessary sensor properties, such as the
sensor's name, units, conersion factors, current and previous values, etc.. It also has methods
for performing various sensor related actions, such as reading a voltage from an ADC channel, converting
that value into the specified units, and updating the sensors priority based on external
information.

There are also various properties and operations specific to the HUD system that need to be
tracked in order to make decisions about how and when to display  information
on the HUD (see calc_priority, hi_thresh, lo_thresh, and priority). The Sensor object is also
used to define and utilize these HUD specific members.
"""

############################
#       Dependencies
############################
import ConfigParser
# import adc

############################
#       Definition
############################
class Sensor(object):
    """
    \brief Constructor for Sensor object.

    The parameters of the Sensor constructor include of all the user-specified (via config file)
    hardware sensor properties which cannot be determined internally. These values are assigned
    upon instantiation to the corresponding Sensor properties. Any other properties are assigned
     default values (generally zero).
    """

    def __init__(self, name, channel, hi_thresh, lo_thresh, hi_bound, lo_bound, conv_coef, conv_offset):
        # name of the sensor (used on the HUD).
        self.name = name

        # Address of the ADC channel to which this sensor is attached.
        self.channel = channel

        # High Threshold: The upper sensor value at which sensor will begin to get displayed.
        self.hi_thresh = hi_thresh

        # Low Threshold: The lower sensor value at which sensor will begin to get displayed.
        self.lo_thresh = lo_thresh

        # High Bound: Maximum possible sensor value (in measured quantity's units)
        self.hi_bound = hi_bound

        # Low Bound: Minimum possible sensor value (in measured quantity's units)
        self. lo_bound = lo_bound

        # Conversion Coefficient:
        # The relationship between the voltage produced by the hardware sensor and the physical
        # parameter represented is assumed to be linear. This is a good approximation in most
        # practical applications. conv_coef is the slope of the linear approximation.
        self.conv_coef = conv_coef

        # Conversion Offset:
        # The relationship between the voltage produced by the hardware sensor and the physical
        # parameter represented is assumed to be linear. This is a good approximation in most
        # practical applications. conv_offset is the offset of the linear approximation.
        self.conv_offset = conv_offset

        # Stores voltage read of the sensor's channel
        self.sensor_read = 0

        # A boolean used to determine whether or not a sensor should be displayed at any given
        # moment. Sensor values are not always displayed in order to avoid information fatigue.
        self.display_me = False

        # The sensor value converted into approriated units.
        self.display_value = 0

    """
    Converts sensor voltage into measured quantity's units.
    """
    def convert(self):
        self.display_value =  self.conv_coef * self.sensor_read + self.conv_offset

    """
    Determines whether sensor value is within defined threshold.
    Sets variable display_me on this basis.
    """
    def check_thresh(self):
        if ( self.display_value <= self.lo_thresh ) or ( self.display_value >= self.hi_thresh ):
            self.display_me = True
        else:
            self.display_me = False

    """
    Dynamically updates all sensor properties.

    Calling update will read the assigned pin value, then call convert, check_thresh,
    and calc_priority.
    """
    def update(voltage):
        self.sensor_read = voltage #adc.readVoltage(self.channel)
        convert()
        check_thresh()

###################################
#   Configuration File Functions
###################################
def parse_sensors():
    """
    Returns configuration object from sensors_config.ini.
    """
    file_address = 'config/sensors_config.ini' # Assume static file structure
    parser = ConfigParser.ConfigParser()
    parser.read(file_address)
    return parser

def get_sensors():
    """
    Returns a list of Sensor objects, parsed from sensors_config.ini
    """
    parser = parse_sensors()
    sensor_list = []
    for section in parser.sections():
        name = parser.get(section, "name")
        channel = parser.get(section, "channel")
        hi_bound = parser.get(section, "upper_bound")
        lo_bound = parser.get(section, "lower_bound")
        hi_thresh = parser.get(section, "upper_threshold")
        lo_thresh = parser.get(section, "lower_threshold")
        conv_coeff = parser.get(section, "conversion_coefficient")
        conv_offset = parser.get(section, "conversion_offset")
        sensor_list.append( Sensor(name, channel, hi_thresh, lo_thresh, hi_bound, lo_bound, conv_coeff, conv_offset) )

    return sensor_list
