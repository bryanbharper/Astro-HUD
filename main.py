#####################
#    Modules
######################
from lib import sensors

sensor_array = sensors.get_sensors()

while True:
    sensor = sensor_array[0]
    sensor.update()
    print '{}\t Voltage= {}\t Value={}'.format(sensor.name, sensor.sensor_read, sensor.display_value)
