##GTK 3 Denemeler

###fatal error: gtk/gtk.h: Böyle bir dosya ya da dizin yok  #include <gtk/gtk.h>
 - sudo apt-get install libgtk-3-dev 
 - gcc <codefile>.c -o <binaryfile> `pkg-config --cflags --libs gtk+-3.0`


###gtk.c:(.text+0x1e): undefined reference to `gtk_init'
 - gcc gtk.c `pkg-config --cflags gtk+-3.0` -o gtk `pkg-config --libs gtk+-3.0`



