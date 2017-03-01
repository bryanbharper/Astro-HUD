import configparser

##############################

config = configparser.configparser()

config['DEFAULT']= {}

ispy=config['libraries']

ispy[Clock]= {}
ispy[FrontEnd]= {}
ispy[Helpers]= {}
ispy[Sensor]= {}

with open('ayeScotty.ini', 'wb') as configfile:
config.write(configfile)
