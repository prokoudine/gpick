/*
 * Copyright (c) 2009-2017, Albertas Vyšniauskas
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *     * Neither the name of the software author nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "CopyMenu.h"
#include "Converters.h"
#include "Converter.h"
#include "GlobalState.h"
#include "CopyMenuItem.h"
GtkWidget* CopyMenu::newMenu(ColorObject *color_object, GtkWidget *palette_widget, GlobalState *gs)
{
	GtkWidget *menu = gtk_menu_new();
	for (auto &converter: gs->converters().allCopy()){
		GtkWidget *item = CopyMenuItem::newItem(color_object, palette_widget, converter, gs);
		if (item) gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
	}
	return menu;
}
GtkWidget* CopyMenu::newMenu(ColorObject *color_object, GlobalState *gs)
{
	GtkWidget *menu = gtk_menu_new();
	for (auto &converter: gs->converters().allCopy()){
		GtkWidget *item = CopyMenuItem::newItem(color_object, converter, gs);
		if (item) gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
	}
	return menu;
}
