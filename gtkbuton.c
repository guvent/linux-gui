#include <gtk/gtk.h>


GtkWidget *button_box;
GtkWidget *window;

static void buton(char*,void*);


static void activate (GtkApplication* app,gpointer user_data);

static void exitapp(GtkWidget *w);


int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app,"activate",G_CALLBACK(activate),0);

	status = g_application_run (G_CALLBACK(app),argc,argv);

	g_object_unref (app);



	return status;



}

static void func()
{
	buton("Deneme 1",buton);

}

static void buton(char* etiket,void* fonksiyon)
{
	GtkWidget *button;
	//etiket = "ok";
 	
	button = gtk_button_new_with_label (etiket);
	g_signal_connect (button, "clicked", G_CALLBACK (fonksiyon), fonksiyon);


	gtk_container_add (GTK_CONTAINER (button_box), button);


  gtk_widget_show_all (window);

}


static void activate (GtkApplication* app,gpointer user_data)
{

  GtkWidget *button;

  //GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Deneme Penceresi...");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Merhaba");
  g_signal_connect (button, "clicked", G_CALLBACK (func), func);



  gtk_container_add (GTK_CONTAINER (button_box), button);


  gtk_widget_show_all (window);

}

static void exitapp(GtkWidget *w)
{
  //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
	gtk_widget_destroy(w);
}
