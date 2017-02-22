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


gchar *dosyaac(GtkButton*,gpointer*);  // dosya aç dialog fonksiyonu öntanımla

int yap(GtkApplication *app,int v)
{

	GtkWidget *w; // pencere nesnesi
	GtkWidget *bx; // box nesnesi

	bx = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); // box un yönü dikine ayarla

	w = gtk_application_window_new(app); // pencere oluştur
	gtk_window_set_default_size(w,600,600);	// boyutu ayarla

	
	GtkWidget *resim = gtk_image_new_from_file ("arrow.jpg"); // örnek bir resimi göster

	GtkWidget *buton = gtk_button_new_with_label("Seç"); // dosya açma diyalogu için buton tanımla (ZORUNLU buton dışında diyalog çağıramadım)
	g_signal_connect(buton,"clicked",G_CALLBACK(dosyaac),resim); // butona dosya aç diyalogunu bağla zaten başka şekilde çalıştıramadık

	gtk_container_add(bx,buton); // butonu box a yerleştir
	gtk_container_add(bx,resim);// image yi box a yerleştir
	gtk_container_add(w,bx); // box u pencereye çiz

	gtk_widget_show_all(w); // pencereyi yenile

	return 0;
}

gchar *dosyaac(GtkButton* buton,gpointer *isteyen) 
// butonla çağırmak zorunda kaldım ve fonksiyonun ilk parametresine çağırdığım butonu nesne olarak gösterdim
{
	gchar *dosyaadi = ""; // dosya adının yazılacağı değişkeni tanımla

	GtkWidget *istemis = GTK_WIDGET (isteyen); // "isteyen" nesne gpointer şeklinde olduğu için GtkWidget nesnesi olarak "istemis" nesnesine gösteriyoruz
	GtkWidget *sahip = gtk_widget_get_toplevel(istemis); // diyalog un bir sahibi olması şart bu sahip nesne "istemis" olarak yukarıda belirlediğimiz nesne olacak

	GtkWidget *diyalog = gtk_file_chooser_dialog_new (("Bir Resim Seç.!"), // bu satırlarda diyalog nesne olarak tanımlanıyor, başlık metni yazılıyor,
		GTK_WINDOW (sahip), GTK_FILE_CHOOSER_ACTION_OPEN, // sahibi belirleniyor, dosya aç tipinde olacağı belirtiliyor,
		"Seçtim", GTK_RESPONSE_ACCEPT, // ilk buton "kabul et" tipinde olması gerektiği ve butonun başlığı "Seçtim" olarak belirleniyor,
		"Vazgeç", GTK_RESPONSE_CANCEL, // ikinci buton ise "iptal et" tipinde olması gerektiği ve butonun başlığı "Vazgeç" olarak belirleniyor,
		 NULL); // parametrelerin bu kadar oldugu en sona belirtiliyor yoksa devam edecek :D



	GtkFileFilter *filtre1 = gtk_file_filter_new (); // ilk filtre tanımlanıyor

	gtk_file_filter_add_pattern (filtre1, "*.png"); // dosya uzantısı belirleniyor
	gtk_file_filter_set_name (filtre1," PNG Resimi '.png' "); // uzantı açıklaması yazılıyor
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (diyalog),filtre1); // filtre ekleniyor

	GtkFileFilter *filtre2 = gtk_file_filter_new (); // ikinci filtre tanımlanıyor

	gtk_file_filter_add_pattern (filtre2, "*.gif"); // dosya uzantısı belirleniyor
	gtk_file_filter_set_name (filtre2," GIF Resimi '.gif' "); // uzantı açıklaması yazılıyor
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (diyalog),filtre2); // filtre ekleniyor

	GtkFileFilter *filtre3 = gtk_file_filter_new (); // üçüncü filtre tanımlanıyor

	gtk_file_filter_add_pattern (filtre3, "*.bmp"); // dosya uzantısı belirleniyor
	gtk_file_filter_set_name (filtre3," Bit Eşlem Resimi '.bmp' "); // uzantı açıklaması yazılıyor
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (diyalog),filtre3); // filtre ekleniyor

	GtkFileFilter *filtre4 = gtk_file_filter_new (); // son filtre de tanımlanıyor

	gtk_file_filter_add_pattern (filtre4, "*.jpg"); // dosya uzantısı belirleniyor
	gtk_file_filter_set_name (filtre4," Fotoğraf Dosyası '.jpg' "); // uzantı açıklaması yazılıyor
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (diyalog),filtre4); // filtre ekleniyor


	
	if(gtk_dialog_run (diyalog) == GTK_RESPONSE_ACCEPT) // diyalog çağırılıyor ve "kabul et" tipi seçilmişse resmi değiştirecek 
	{
		dosyaadi = gtk_file_chooser_get_filename (diyalog); // seçilen dosyanın adı veya yolu değişkene alınıyor
		gtk_image_set_from_file (GTK_IMAGE (istemis), dosyaadi); // resim değiştiriliyor
	}
	gtk_widget_destroy (diyalog); // diyalog la işimiz bitti kapanıyor

	return dosyaadi; // kullanılmıyor fakat lazım olur boş dönmesin diye resim adını fonksiyon geri çeviriyor

}

