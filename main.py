#####################
#    Modules
######################
from lib import sensors

sensor_array = sensors.get_sensors()

for sensor in sensor_array:
    print sensor.name
