/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2016 Ivan Guerreschi
 * 
 * Calcolatrice is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Calcolatrice is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <stdlib.h>

struct calcInput {
	gdouble number;
	gchar op;
} c;

static void zero(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "0", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void one(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "1", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void two(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "2", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void three(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "3", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void four(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "4", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void five(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "5", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void six(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "6", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void seven(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "7", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void eight(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "8", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void nine(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, "9", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void add(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	c.number = atof(getNumber);	
	c.op = '+';
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void sott(GtkWidget *widget, gpointer entry)
{	
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	c.number = atof(getNumber);
	c.op = '-';
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void molt(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	c.number = atof(getNumber);
	c.op = '*';
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void divd(GtkWidget *widget, gpointer entry)
{	
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	c.number = atof(getNumber);
	c.op = '/';
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void point(GtkWidget *widget, gpointer entry)
{
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));
	gchar *stringa = g_strconcat(getNumber, ",", NULL);
	gtk_entry_set_text(GTK_ENTRY(entry), stringa);
}

static void equal(GtkWidget *widget, gpointer entry)
{		
	gchar buf[50];
	const gchar *getNumber = gtk_entry_get_text(GTK_ENTRY(entry));

	switch (c.op) {
		case '+':
			sprintf(buf, "%.3f", c.number + atof(getNumber));
			break;
		case '-':
			sprintf(buf, "%.3f", c.number - atof(getNumber));
			break;
		case '*':
			sprintf(buf, "%.3f", c.number * atof(getNumber));
			break;
		case '/':
			sprintf(buf, "%.3f", c.number / atof(getNumber));
			break;
	}	
	
	gtk_entry_set_text(GTK_ENTRY(entry), buf);
}

static void canc(GtkWidget *widget, gpointer entry)
{
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;	
	GtkWidget *gridContent;
	GtkWidget *entryResult;
	GtkWidget *buttonZero;
	GtkWidget *buttonOne;
	GtkWidget *buttonTwo;
	GtkWidget *buttonThree;
	GtkWidget *buttonFour;
	GtkWidget *buttonFive;
	GtkWidget *buttonSix;
	GtkWidget *buttonSeven;
	GtkWidget *buttonEight;
	GtkWidget *buttonNine;
	GtkWidget *buttonAdd;
	GtkWidget *buttonSot;
	GtkWidget *buttonMolt;
	GtkWidget *buttonDiv;
	GtkWidget *buttonCanc;
	GtkWidget *buttonPoint;
	GtkWidget *buttonEqual;
	
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Calcolatrice");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);	
	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

	entryResult = gtk_entry_new();
	
	buttonZero = gtk_button_new_with_label("0");
	buttonOne = gtk_button_new_with_label("1");
	buttonTwo = gtk_button_new_with_label("2");
	buttonThree = gtk_button_new_with_label("3");
	buttonFour = gtk_button_new_with_label("4");
	buttonFive = gtk_button_new_with_label("5");
	buttonSix = gtk_button_new_with_label("6");
	buttonSeven = gtk_button_new_with_label("7");
	buttonEight = gtk_button_new_with_label("8");
	buttonNine = gtk_button_new_with_label("9");
	buttonAdd = gtk_button_new_with_label("+");
	buttonSot = gtk_button_new_with_label("-");
	buttonMolt = gtk_button_new_with_label("*");
	buttonDiv = gtk_button_new_with_label("/");
	buttonCanc = gtk_button_new_with_label("C");
	buttonPoint = gtk_button_new_with_label(".");
	buttonEqual = gtk_button_new_with_label("=");

	gridContent = gtk_grid_new();
	gtk_grid_set_row_spacing (GTK_GRID (gridContent), 5);
	gtk_grid_set_column_spacing(GTK_GRID (gridContent), 5);
	gtk_grid_set_column_homogeneous(GTK_GRID(gridContent), TRUE);
	gtk_grid_set_row_homogeneous(GTK_GRID(gridContent), TRUE);

	gtk_container_add(GTK_CONTAINER(window), gridContent);
	
	gtk_grid_attach(GTK_GRID(gridContent), entryResult  , 0, 0, 3, 1);
	
	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonSeven, entryResult,
 	                     GTK_POS_BOTTOM, 1, 1);
	
	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonEight, buttonSeven, 
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonNine, buttonEight, 
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonFour, buttonSeven, 
 	                     GTK_POS_BOTTOM, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonFive, buttonFour,  
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonSix, buttonFive,   
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonOne, buttonFour, 
 	                     GTK_POS_BOTTOM, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonTwo, buttonOne,    
 	                     GTK_POS_RIGHT, 1, 1);
	
	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonThree, buttonTwo,     
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonZero, buttonOne, 
 	                     GTK_POS_BOTTOM, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonAdd, buttonZero,     
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonSot, buttonAdd,      
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonMolt, buttonZero, 
 	                     GTK_POS_BOTTOM, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonDiv, buttonMolt,      
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonPoint, buttonDiv,       
 	                     GTK_POS_RIGHT, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonCanc, buttonMolt, 
 	                     GTK_POS_BOTTOM, 1, 1);

	gtk_grid_attach_next_to(GTK_GRID(gridContent), buttonEqual, buttonCanc,       
 	                     GTK_POS_RIGHT, 2, 1);


	g_signal_connect(buttonZero, "clicked",G_CALLBACK(zero), entryResult);
	g_signal_connect(buttonOne, "clicked",G_CALLBACK(one), entryResult);
	g_signal_connect(buttonTwo, "clicked",G_CALLBACK(two), entryResult);
	g_signal_connect(buttonThree, "clicked",G_CALLBACK(three), entryResult);
	g_signal_connect(buttonFour, "clicked",G_CALLBACK(four), entryResult);
	g_signal_connect(buttonFive, "clicked",G_CALLBACK(five), entryResult);
	g_signal_connect(buttonSix, "clicked",G_CALLBACK(six), entryResult);
	g_signal_connect(buttonSeven, "clicked",G_CALLBACK(seven), entryResult);
	g_signal_connect(buttonEight, "clicked",G_CALLBACK(eight), entryResult);
	g_signal_connect(buttonNine, "clicked",G_CALLBACK(nine), entryResult);
	g_signal_connect(buttonAdd, "clicked",G_CALLBACK(add), entryResult);
	g_signal_connect(buttonSot, "clicked",G_CALLBACK(sott), entryResult);
	g_signal_connect(buttonMolt, "clicked",G_CALLBACK(molt), entryResult);
	g_signal_connect(buttonDiv, "clicked",G_CALLBACK(divd), entryResult);
	g_signal_connect(buttonCanc, "clicked",G_CALLBACK(canc), entryResult);
	g_signal_connect(buttonPoint, "clicked",G_CALLBACK(point), entryResult);
	g_signal_connect(buttonEqual, "clicked",G_CALLBACK(equal), entryResult);
	
	gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{	
	GtkApplication *app;
	int status;
	
	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}