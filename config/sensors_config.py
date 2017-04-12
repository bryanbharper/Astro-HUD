# creates new config file
def make(sect, chan, nam, up_bound, lo_bound, up_thresh, lo_thresh, conv_coef, conv_off):
"everything is values in accordance to their variable name"

    #filename -> path file for the .ini
    filename = "config/sensors_config.ini"

    cfgfile = open(filename,'w')

    #adds section to config file eg. [section]
    Config.add_section(sect)

    #sets variables and values under the specijfied section
    # eg. [section]
    # eg. var=val
    Config.set(sect, 'channel', chan)
    Config.set(sect, 'name', nam)
    Config.set(sect, 'upper_bound', up_bound)
    Config.set(sect, 'lower_bound', lo_bound)
    Config.set(sect, 'upper_threshold', up_thresh)
    Config.set(sect, 'lower_threshold', lo_thresh)
    Config.set(sect, 'conversion_coefficient', conv_coef)
    Config.set(sect, 'conversion_offset', conv_off)

    #writes information to the configuration file
    Config.write(cfgfile)
    cfgfile.close()
