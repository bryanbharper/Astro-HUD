#####################
#    Modules
######################
from lib import sensors
from lib import adc

sensor_array = sensors.get_sensors()

while True:
    sensor = sensor_array[0]
    sensor.update( adc.readVoltage(sensor.channel) )
    print '{}\t Voltage= {}\t Value={}'.format(sensor.name, sensor.sensor_read, sensor.display_value)
