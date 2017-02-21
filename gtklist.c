#include <gtk/gtk.h>



int yap(); // yap fonksiyonu öntanımlanıyor..

int main(int argc,char **argv)
{
	GtkApplication *app; //gtk app tanımla..
	int stat; //gtk app çalıştıktan sonra dönecek olan status..

	app = gtk_application_new("org.gtk.gtk",0); //gtk app oluştur..
	g_signal_connect(app,"activate",G_CALLBACK(yap),0); //gtk app için çalıştırma bağlantısı "yap()" fonksiyonu ile..
	
	stat = g_application_run(G_CALLBACK(app),argc,argv); // gtk app çalıştır ve "return;" sonucu al..

	g_object_unref(app); // gtk app durdurulunca app nesnesini sil...

	return stat; // dönecek olan status..
}

enum {SUTUN1, SUTUN2, SUTUN3, SUTUN4, /* buraya istenilen kadar sütun eklenebilir */
    RENK, SUTUN
};

int yap(GApplication *app,int v)
{
	GtkWidget *w; // pencere nesnesi
	
	w = gtk_application_window_new(app); // gtk app penceresi oluştur
	gtk_window_set_default_size(w,600,600);	// pencereyi boyutlandır



//tree_view başla...

    GtkListStore*      model; // tree_view için model - içinde sütun satır nesneleri olacak..
    GtkWidget*         view; // tree_view nesnesi
    GtkTreeViewColumn* column; // sütunlar



//sütun modeli
model = gtk_list_store_new(SUTUN,
                               G_TYPE_STRING,   /* İsim */
                               G_TYPE_UINT,     /* Offset */
                               G_TYPE_UINT,     /* Boyut */
                               G_TYPE_STRING,   /* Açıklama */
				/* Buraya istenilen kadar eklenen sütunu modellemek gerekir */
                               G_TYPE_STRING    /* Renk */
                              );



//model tree_view e tanımlanıyor..
view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));

//       g_object_unref(model);
// sonradan ekleme yapabilmemiz için model devreden çıkmamalı..


//sütun modeli şekilleniyor..
column = gtk_tree_view_column_new_with_attributes("İsim", gtk_cell_renderer_text_new(), "text", SUTUN1, "background", RENK, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

column = gtk_tree_view_column_new_with_attributes("Offset", gtk_cell_renderer_text_new(), "text", SUTUN2, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

column = gtk_tree_view_column_new_with_attributes("Boyut", gtk_cell_renderer_text_new(), "text", SUTUN3, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);




/***  içerik satırı ilave ediliyor.. ***/
gtk_list_store_insert_with_values(model, NULL, -1, SUTUN1, "Birinci Satır", SUTUN2, 532, SUTUN3, 10, -1);
gtk_tree_view_set_model(view,model);

/***  içerik satırı için iki satır komutu tekrarla.. ***/


// tree_view son....

	

	gtk_container_add(GTK_CONTAINER(w),view); // tree_view pencere içine çiz..

	gtk_widget_show_all(w);	// gtk çizimi yeniden göster - yenile ile aynı mantık :D

}

