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

class CharacterHUD : public Gtk::Window {
public:
    CharacterHUD();
    virtual ~CharacterHUD();
protected:
    //Signal handlers:
    //Our new improved on_button_clicked()
    void on_button_clicked(Glib::ustring data);
    
    //Child widgets:
    Gtk::Grid m_grid;
    Gtk::Image m_character_hud;
    Gtk::Image m_background_1;
    Gtk::Image m_character;
    Gtk::Image m_character_name;
    
    Gtk::Image m_ammo;
    Gtk::Image m_ammo_name;
    
};

#endif /* CHARACTERHUD_H */

