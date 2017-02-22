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

void menudosyaac(GtkWidget *a,GtkWidget *b);
void cikisyap(GtkWidget *a,GtkWidget *b);

int yap(GtkApplication *app,int v)
{

	GtkWidget *w; // pencere nesnesi
	GtkWidget *bx; // box nesnesi

	bx = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); // box un yönü dikine ayarla

	w = gtk_application_window_new(app); // pencere oluştur
	gtk_window_set_default_size(w,200,200);	// boyutu ayarla
	gtk_window_set_title(w,"Gtk Menü Denemesi..");

	GtkWidget *vbox; // menü için vbox a ihtiyaç var oluşturuyoruz

	vbox = gtk_vbox_new(FALSE, 0); // vbox u tanımlıyoruz
	gtk_container_add(GTK_CONTAINER(w), vbox); // vbox u pencereye yerleştiriyoruz


	GtkWidget *menu; // menü bar nesnesi
	GtkWidget *anamenu; // ana menü nesnesi
	
	GtkWidget *anamenubuton; // ana menü için buton nesnesi	
	GtkWidget *menuac; // dosya aç seçeneği nesnesi
	GtkWidget *menucikis; // çıkış seçeneği nesnesi
	GtkWidget *ara; // aralık nesnesi (iki menü arasına çizgi çizecek olan)


	menu = gtk_menu_bar_new(); // menü bar ı tanımlıyoruz
	anamenu = gtk_menu_new(); // ana menü yü tanımlıyoruz
	//   -------------------------------------------------
	//   | [X][-][O]    --MENÜBAR--                      |
	//   -------------------------------------------------

	anamenubuton = gtk_menu_item_new_with_label("Menü"); // ana menü için buton nesnesi oluşturuyoruz
	//   -------------------------------------------------
	//   | [X][-][O]    | Menü  |                        |
	//   -------------------------------------------------

	menuac = gtk_menu_item_new_with_label("Dosya Aç"); // dosya aç seçimi için buton oluşturuyoruz
	//   -------------------------------------------------
	//   | [X][-][O]    | Menü  |                        |
	//   -------------------------------------------------
	//   |              | Dosya Aç  |                    |
	//   -------------------------------------------------

	ara = gtk_separator_menu_item_new(); // aralık bırakıyoruz
	//   -------------------------------------------------
	//   | [X][-][O]    | Menü  |                        |
	//   -------------------------------------------------
	//   |              | Dosya Aç  |                    |
	//   -------------------------------------------------
	//   |              | --------- |                    |
	//   -------------------------------------------------

	menucikis = gtk_menu_item_new_with_label("Çıkış"); // çıkış seçimi iiçin buton oluşturuyoruz
	//   -------------------------------------------------
	//   | [X][-][O]    | Menü  |                        |
	//   -------------------------------------------------
	//   |              | Dosya Aç  |                    |
	//   -------------------------------------------------
	//   |              | --------- |                    |
	//   -------------------------------------------------
	//   |              | Çıkış     |                    |
	//   -------------------------------------------------

	

	gtk_menu_shell_append(GTK_MENU_SHELL(menu), anamenubuton); // menü bar a ana menüyü bağlıyoruz
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(anamenubuton), anamenu); // ana menü ye butonunu bağlıyoruz

	gtk_menu_shell_append(GTK_MENU_SHELL(anamenu), menuac); // dosya aç butonunu ana menüye yerleştiriyoruz
	gtk_menu_shell_append(GTK_MENU_SHELL(anamenu), ara); // bıraktığımız aralığı ana menüye yerleştiriyoruz
	gtk_menu_shell_append(GTK_MENU_SHELL(anamenu), menucikis); // çıkış butonunu ana menüye yerleştiriyoruz


	g_signal_connect(G_OBJECT(menuac), "activate", G_CALLBACK(menudosyaac), w); // dosya aç butonuna "menudosyaac()" fonksiyonunu bağlıyoruz
	g_signal_connect(G_OBJECT(menucikis), "activate", G_CALLBACK(cikisyap), w); // çıkış butonuna "cikisyap()" fonksiyonunu bağlıyoruz


	gtk_box_pack_start(GTK_BOX(vbox), menu, FALSE, FALSE, 0); // son olarak menü bar ı vbox a paketliyoruz
	
	gtk_container_add(w,bx); // box u pencereye çiz

	gtk_widget_show_all(w); // pencereyi yenile

	return 0;
}

void menudosyaac(GtkWidget *a,GtkWidget *b)
{
	g_print("Açılır inşallah :D\n");
}


void cikisyap(GtkWidget *a,GtkWidget *b)
{
	gtk_widget_destroy(b);
}

