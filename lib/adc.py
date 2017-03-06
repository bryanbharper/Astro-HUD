"""@package docstring
Functions related to reading voltages from analog to digital converter.
In development, the MCP3208 ADC was used.

"""

############################
#       Dependencies
############################
import spidev


############################
#   Functions
############################
def readChannel(channel):
    port = 0
    device = 0
    # Open SPI bus
    spi = spidev.SpiDev()
    spi.open(port, device)
    # Transfer and decode data
    transfer = spi.xfer2( [ 6 + ( (channel&4) >> 2 ), (channel&3) << 6, 0] )
    data = ( (transfer[1] & 15) << 8 ) + transfer[2]
    # Close spi bus
    spi.close()
    return data


def readVoltage(channel):
    # Configuration
    round_decimal_places = 4
    vref = 3.3 # MCP3208 Options: 5.0, 3.3, 1.0, 0.3 see datasheet
    sample_rate = 4096
    # Retreive data
    data = readChannel(channel)
    # Convert to volts (optionally round value)
    voltage = (vref * data) / float(sample_rate)
    voltage = round( voltage, round_decimal_places)
    return voltage
