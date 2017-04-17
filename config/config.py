import configparser

##############################

config = configparser.ConfigParser()

#Default settings for the configfile
config['DEFAULT']= {}


i_spy=config['settings']

i_spy sets libraries
i_spy['Clock']= {}
i_spy['FrontEnd']= {}
i_spy['Helpers']= {}
i_spy['Sensor']= {}

# measu sets the Sensors
measu=i_spy['Sensor']

# scout sets the CO2 sensor in configfile
scout=measu['Oxygen']

# might not need scout type
#   if we keep i_spy. but if
#   not it's an easy fix
scout['type']= 'sensor'
scout['wireless']= 'false'
scout['pin']= '13'
scout['display_name']= 'Oxygen'
scout['hi_bound']= '100'
scout['lo_bound']= '0'
scout['hi_thresh']= '100'
scout['lo_thresh']= '0'
scout['conv_coef']= '231/100'
scout['conv_offset']= '3'
scout['double name']= 'D_name'
scout['double value']= 'D_val'

# agent sets the CO2 sensor in configfile
agent=measu['CO2']

agent['type']= 'sensor'
agent['wireless']= 'true'
agent['pin']= '7448'
agent['display_name']= 'CO2'
agent['hi_bound']= '1000'
agent['lo_bound']= '2'
agent['hi_thresh']= '678'
agent['lo_thresh']= '429'
agent['conv_coef']= '1.8'
agent['conv_offset']= '0'

# configfile is ayeScotty.ini
# named after StarTrek
with open('ayeScotty.ini', 'wb') as configfile:
    config.write(configfile)
