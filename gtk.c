#include <gtk/gtk.h>


int yap();
void buton();

int main(int argc,char **argv)
{
	GtkApplication *app;
	int stat;

	app = gtk_application_new("org.gtk.gtk",0);
	g_signal_connect(app,"activate",G_CALLBACK(yap),0);
	
	stat = g_application_run(G_CALLBACK(app),argc,argv);

	g_object_unref(app);

	return stat;
}

int yap(GApplication *app,int v)
{
	GtkWidget *w;
	GtkWidget *b;
	
	w = gtk_application_window_new(app);
	gtk_window_set_default_size(w,200,200);	

	b = gtk_button_new_with_label("ben");
	gtk_container_add(GTK_CONTAINER(w),b);
	g_signal_connect(b,"clicked",G_CALLBACK(buton),0);

	gtk_widget_show_all(w);

	g_print("yapıldı\n");
}

void buton()
{
	g_print("ben\n");
}
