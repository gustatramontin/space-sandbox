##
#
#
# @file
# @version 0.1
main: main.c
	gcc -o space-sandbox main.c gfx.c `sdl2-config --cflags --libs` -lm


# end
