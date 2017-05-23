/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HelloWorld.h
 * Author: usuario
 *
 * Created on 16 de mayo de 2017, 12:00
 */

#ifndef CHARACTERHUD_H
#define CHARACTERHUD_H

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>

class SeleccionadoHUD : public Gtk::Window {
public:
    SeleccionadoHUD();
    virtual ~SeleccionadoHUD();
    void seleccionarFabrica();
    void seleccionarPersonaje();
protected:
    //Signal handlers:
    //Our new improved on_button_clicked()
    void on_button_clicked();
    bool on_timeout();
    
    //Child widgets:
    Gtk::Grid m_grid;
    Gtk::Image m_character_hud;
    Gtk::Image m_background_1;
    Gtk::Image m_character;
    Gtk::Image m_character_name;
    
    Gtk::Image m_ammo;
    Gtk::Image m_ammo_name;

    Gtk::Button m_button;
    
};

#endif /* CHARACTERHUD_H */

