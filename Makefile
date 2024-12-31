##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##
pathdir = src/lib

NAME = libmy

SRC	=	src/my_radar.c \
		src/entity.c \
		src/event.c \
		src/sprite.c \
		src/window.c \
		src/draw_entity.c \
		$(pathdir)/my_compute_power_rec.c \
		$(pathdir)/my_compute_square_root.c \
		$(pathdir)/my_isneg.c \
		$(pathdir)/my_put_nbr.c \
		$(pathdir)/my_putchar.c \
		$(pathdir)/my_putstr.c \
		$(pathdir)/my_revstr.c \
		$(pathdir)/my_strcat.c \
		$(pathdir)/my_strcpy.c \
		$(pathdir)/my_strlen.c \
		$(pathdir)/my_strncat.c \
		$(pathdir)/my_strncpy.c \
		$(pathdir)/flag_c.c \
		$(pathdir)/flag_d.c \
		$(pathdir)/flag_i.c \
		$(pathdir)/flag_o.c \
		$(pathdir)/flag_percent.c \
		$(pathdir)/flag_s.c \
		$(pathdir)/flag_x.c \
		$(pathdir)/flag_x2.c \
		$(pathdir)/my_printf.c

OBJ  	=	 $(SRC:.c=.o)

LIB_OBJ =  $(LIB:.c=.o)

RADAR = my_radar

CFLAGS = -Iinclude -L libmy -lcsfml-graphics -lcsfml-window -lcsfml-audio \
		-lcsfml-network -lcsfml-system -Wall

$(RADAR): $(OBJ)
		gcc $(OBJ) -o $(RADAR) $(CFLAGS)

all: 	$(RADAR)

clean:
		rm -f $(OBJ)
		rm -f $(LIB_OBJ)

fclean: clean
		rm -f $(RADAR)

re:
		$(MAKE) fclean
		$(MAKE) all

debug:
		$(MAKE) clean
		gcc -g $(SRC) -o $(RADAR) $(CFLAGS)
