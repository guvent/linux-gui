#include <gtk/gtk.h>


int yap();


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
	GtkWidget *p;
	
	w = gtk_application_window_new(app);
	gtk_window_set_default_size(w,200,200);	
	

	p = gtk_progress_bar_new();
	gtk_progress_bar_set_fraction(p,0.8);
	gtk_progress_bar_set_show_text(p,TRUE);

	gtk_container_add(GTK_CONTAINER(w),p);

	gtk_widget_show_all(w);

}
