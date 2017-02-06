'''
Example Module:
This is a description of the types of definitions (functions, obects, etc.)
contained in this module.

Any information pertinent to the use of this module can be included here.
'''

############################
#       Dependencies
############################
import math
import turtle

##############################################################################
# Square:
# Description: Uses the turtle module to draw a square.
# The parameter 'turt' must be a Turtle() object.
###############################################################################
def square(t, length):
    for i in range(4):
        t.fd(length)
        t.lt(90)
    turtle.mainloop()

###############################################################################
# Polygon:
# Descrioption: Uses the turtle module to drawn an n-sided reagular polygon
# The parameter 'turt' must be a Turtle() object.
###############################################################################
def polygon(turt, length, num_sides):
    for i in range(num_sides):
        turt.fd(length)
        turt.lt(360 / num_sides)
    turtle.mainloop()

###############################################################################
# Circle:
# Description: Uses the turtle module and the polygon() function to draw a circle
# Dependencies: polygon()
# The parameter 'turt' must be a Turtle() object.
###############################################################################
def circle(turt, radius):
    num_sides = 100
    side_length = int((2*math.pi*radius)/num_sides)
    polygon(turt, side_length, num_sides)

###############################################################################
# Arc:
# Description: Uses turtle module to draw an arc
# Dependencies: polygon()
# The parameter 'turt' must be a Turtle() object.
###############################################################################
def arc(turt, radius, angle):
    num_sides = 50
    side_length = int((2*math.pi*radius)/num_sides)
    polygon(turt, side_length, num_sides)
