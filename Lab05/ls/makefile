
all: ls_r.c show_file_info.c mode_to_letters.c uid_to_name.c gid_to_name.c do_ls.c dostat.c
	gcc -Wall -g ls_r.c  \
   show_file_info.c \
   mode_to_letters.c \
   uid_to_name.c \
   gid_to_name.c \
   do_ls.c \
   dostat.c \
   recursive_ls.c \
   -o ls_r.exe

clean:
	rm ls_r.exe
