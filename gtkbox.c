#include <gtk/gtk.h>


int yap();


int main(int argc,char **argv)
{
	GtkApplication *app;					/* ------------------------------*/
	int stat;

	app = gtk_application_new("org.gtk.gtk",0);
	g_signal_connect(app,"activate",G_CALLBACK(yap),0);
	
	stat = g_application_run(G_CALLBACK(app),argc,argv);	/*  Bunları Biliyorsunuz Zaten  */

	g_object_unref(app);

	return stat;						/*------------------------------*/
}

int yap(GtkApplication *app,int v)
{

	GtkWidget *w; // pencere nesnesi
	GtkWidget *bx; // box nesnesi

	bx = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); // box un yönü dikine ayarla

	w = gtk_application_window_new(app); // pencere oluştur
	gtk_window_set_default_size(w,200,200);	// boyutu ayarla


	/* Buradan Devam Ediyorsun... */ 
	
	gtk_container_add(w,bx); // box u pencereye çiz

	gtk_widget_show_all(w); // pencereyi yenile

	return 0;
}



