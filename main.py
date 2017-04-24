#####################
#    Modules
######################
import random
from lib import sensors
from lib import adc
import gi
from gi.repository import GLib
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk



# Define GUI Object
class SensorHUD(Gtk.Window):
    
    def __init__(self):
        # Initialize parent
        Gtk.Window.__init__(self)

        # Give SensorGUI attribute which stores information about sensors.
        self.sensors = []

        # Create attributes to track the sensor name and value labels
        self.sensor_name_labels = []
        self.sensor_value_labels = []

        # Create a grid for sensor names and values to be listed in
        self.grid = Gtk.Grid()
        self.grid.set_row_spacing(10)
        self.grid.set_column_spacing(10)
        self.add(self.grid)


    def generate_labels(self):
        """
        For each sensor two labels will be created: one label for the sensor name and one label
        for the sensor value. These labels will be held in two corresponding lists.
        Each of these sensors is then attached to the grid.
        """

        for i in range( len(self.sensors) ):
            # Create lists of sensor name and values labels
            name_tag = self.sensors[i].name  + ":"
            self.sensor_name_labels.append( Gtk.Label( name_tag ) )
            self.sensor_value_labels.append( Gtk.Label( self.sensors[i].display_value ) )

            # Set alignment for each labels
            self.sensor_name_labels[i].set_alignment(xalign=0.0, yalign=0.5) # Left Align
            self.sensor_value_labels[i].set_alignment(xalign=1.0, yalign=0.5) # Right align



            # Attach sensor name and value labels to grid side by side
            self.grid.attach( self.sensor_name_labels[i], 0, i, 1, 1 )
            self.grid.attach( self.sensor_value_labels[i], 1, i, 1, 1 )

    def update_sensors(self):
        for i in range( len(self.sensors) ):
            voltage = adc.readVoltage( self.sensors[i].channel )
            self.sensors[i].update( voltage )
            self.sensor_value_labels[i].set_text( str(self.sensors[i].display_value) )
        return True  # must return true for timeout function to continue executing





# Get sensors from configuration file
sensor_list = sensors.get_sensors()


# Create instand of SensorHUD
hud = SensorHUD()
hud.connect("delete-event", Gtk.main_quit)

hud.sensors= sensor_list
hud.generate_labels()
GLib.timeout_add(250, hud.update_sensors)

hud.show_all()
Gtk.main()
