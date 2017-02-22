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

GtkWidget *w; // pencere nesnesi
GtkWidget *t; // text_view nesnesi
GtkTextBuffer *tb = NULL; // text_buffer nesnesi
gchar *tx; //okunan metin

void oku(); // oku fonksiyonu öntanımla

int yap(GApplication *app,int v)
{

	/* Butonu sonradan eklemek durumunda kaldım
	   textview den okuma yapmak için kullandım */

	GtkWidget *b; // buton
	GtkWidget *bx; // box

	b = gtk_button_new_with_label("tamam"); // tamam adında buton oluştur
	bx = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); // box un yönü dikine ayarla
	
	g_signal_connect(b,"clicked",G_CALLBACK(oku),0); // button a oku fonksiyonu

	/* Buton için GtkBox da gerekti malum textview ile
	   button u alt alta göstermek gerekiyor */


	w = gtk_application_window_new(app); // pencere oluştur
	gtk_window_set_default_size(w,200,200);	// boyutu ayarla
	

	t = gtk_text_view_new(); // text_view oluştur

	tb= gtk_text_buffer_new(NULL); // text_buffer oluştur


	// text_view e yaz
	gtk_text_buffer_set_text(tb,"okeeeyy",-1); // text_buffer e metin gir

	gtk_text_view_set_buffer(t,tb); // içinde metin olan text_buffer i text_view e dahil et


	gtk_container_add(bx,t); // text_view i box a çiz

	gtk_container_add(bx,b); // button u box a çiz
	gtk_container_add(w,bx); // box u da pencereye çiz


	gtk_widget_show_all(w); // pencereyi yenile..

}


void oku()
{
	// text_view den oku
	GtkTextIter ilk,son; // buffer için iter değişkeni lazım

	tb = gtk_text_view_get_buffer(t); // buffer oluştur text_view e bağla

	gtk_text_buffer_get_bounds(tb,&ilk,&son); 
	// iter değişkenlerini referans et
	// burada dikkat ederseniz iter değişkenleri referans olarak gösterilmiş
	// bu get_bounds fonksiyonu ile buffer de olan verinin başlangıç ve
	// son pozisyonlarını değişkene direkt yazacak ki buffer_get_text fonksiyonu
	// o bilgiler üzerinden doğrudan yürüyebilecek..

	tx = gtk_text_buffer_get_text(tb,&ilk,&son,FALSE); // bufferden metini al
	

	gtk_window_set_title(w,tx); // metni şimdilik pencerenin başlığına yaz..
}




