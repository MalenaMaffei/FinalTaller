/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HelloWorld.cpp
 * Author: usuario
 * 
 * Created on 16 de mayo de 2017, 12:00
 */

#include "CharacterHUD.h"
#include <iostream>
#include <gdk/gdk.h>
#include <gdkmm/pixbuf.h>
#include <gdkmm/rgba.h>
#include <gtkmm-3.0/gtkmm/grid.h>
#include <gtkmm-3.0/gtkmm/drawingarea.h>
#include <gtkmm-3.0/gtkmm/layout.h>

CharacterHUD::CharacterHUD () { 
	
	Gtk::Window::set_decorated(false);
	Gtk::Window::set_position(Gtk::WIN_POS_CENTER);
	Gtk::Window::set_resizable (false);
	m_character_hud = Gtk::Image("selected_character_1.png");
	m_background_1 = Gtk::Image("backdrop_desert.bmp");
	m_character = Gtk::Image("red_grunt.png");
	m_character_name = Gtk::Image("red_grunt_label.bmp");	
	m_ammo = Gtk::Image("gatling_icon.png");
    m_ammo_name = Gtk::Image("gatling_label.bmp");
	
	Gtk::Window::add(m_grid);
	
	m_grid.attach(m_character_name,1,-1,100,100);
	m_grid.attach(m_ammo,0,35,100,100);
	m_grid.attach(m_ammo_name,1,75,100,100);
	m_grid.attach(m_character_hud,0,0,100,100);
	m_grid.attach(m_character,5,-42,100,100);
	m_grid.attach(m_background_1,2,-42,100,100);
	
	show_all_children();
	
	Gtk::Window::set_keep_above (true);
}

CharacterHUD::~CharacterHUD () { }


