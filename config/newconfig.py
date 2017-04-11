# creates new config file

#filename -> path file for the .ini
filename = "c:\\config\name.ini"
#sect -> section name
sect = 'section'
#var -> names a variable within a section
var = 'variable'
#val1 -> defines the variable a specified value
val = value

#creates .ini configuration file
cfgfile = open(filename,'w')

#adds section to config file eg. [section]
Config.add_section(sect)
#sets variables and values under the specified section
# eg. [section]
# eg. var=val
Config.set(sect,var, val)

#writes information to the configuration file
Config.write(cfgfile)
cfgfile.close()
