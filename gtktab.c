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


GtkWidget *tabolustur(int index); // Tab oluşturma fonksiyonu nu öntanımla

int yap(GtkApplication *app,int v)
{

	GtkWidget *w; // pencere nesnesi
	GtkWidget *bx; // box nesnesi

	bx = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); // box un yönü dikine ayarla

	w = gtk_application_window_new(app); // pencere oluştur
	gtk_window_set_default_size(w,200,200);	// boyutu ayarla

	GtkWidget *tab; // tab nesnesi
	tab = gtk_notebook_new(); // tab oluştur

	GtkWidget *label1 = gtk_label_new("Birinci"); // Başlık metini 1
	GtkWidget *label2 = gtk_label_new("İkinci"); // Başlık metini 2
	GtkWidget *label3 = gtk_label_new("Sonuncu"); // Başlık metini 3
	
	
	// tab a içerik oluştururken tabolustur() fonksiyonunu çağırır
	// tabolustur fonksiyonunun parametresine oluşturulacak tab içeriğinin index ini belirtir
	// index e göre de tabolustur() içeriği yerleştirecektir o fonksiyon aşağıda..
	gtk_notebook_append_page(tab,tabolustur(0),label1); // tab a içerik oluştur 1
	gtk_notebook_append_page(tab,tabolustur(1),label2); // tab a içerik oluştur 2
	gtk_notebook_append_page(tab,tabolustur(2),label3); // tab a içerik oluştur 3
	
	
	gtk_container_add(bx,tab); // tab ı box a yerleştir
	gtk_container_add(w,bx); // box u pencereye çiz

	gtk_widget_show_all(w); // pencereyi yenile

	return 0;
}

GtkWidget *tabolustur(int index)
{
	GtkWidget *context; // içerik nesnesi
	context = gtk_vbox_new (FALSE, 4); // içerik için vbox oluştur
	gtk_container_set_border_width (GTK_CONTAINER (context), 4); // vbox a border çizgisi ayarı
	
	GtkWidget *label1 = gtk_label_new("Birinci İçerik Örneği"); // örnek bir içerik
	GtkWidget *label2 = gtk_label_new("İkinci İçerik Örneği"); // örnek bir içerik daha
	GtkWidget *label3 = gtk_label_new("Üçüncü İçerik Örneği"); // ve bir örnek içerik daha
	

	// burada mantık tab kaç adet olacaksa o kadar "case x: break;" yapılır ki o kadar içeriğin 
	// olacağı baştan çizilip yerleştirilmiş olsun sonrasında zaten başlık metinlerine tıklandıkça
	// yerleştirilen tab içeriklerini görmüş olacağız..
	switch(index) // parametreden index alınır
	{
		case 0: // değere göre içerik yerleştirilir
		gtk_container_add(context,label1); 
	break;
		case 1: // değere göre içerik yerleştirilir
		gtk_container_add(context,label2); 
	break;
		case 2: // değere göre içerik yerleştirilir
		gtk_container_add(context,label3); 
	break;
	}

	gtk_widget_show (context); // son olarak içerik tab a çizilir

	return context;
}

