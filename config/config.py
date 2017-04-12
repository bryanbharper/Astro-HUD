# creates new config file
def make(sections, variable_name, value):
"sections and variable_name are both string arrays"
    sect = sections
    var_name = variable_name
    val = value

#filename -> path file for the .ini
filename = "config/sensors_config.ini"
#sect -> section name
sect = 'section'
#var_name -> names a variable within a section
var_name = 'variable'
#val1 -> defines the variable a specified value
val = value

#creates .ini configuration file
cfgfile = open(filename,'w')

def set_config():
    for x in sect:
    #adds section to config file eg. [section]
    (Config.add_section(x))
        for y in var_name:
            Config.set(sect,y,val )



#sets variable_name and values under the specijfied section
# eg. [section]
# eg. var_name=val
Config.set(sect,var_name, val)

#writes information to the configuration file
Config.write(cfgfile)
cfgfile.close()
