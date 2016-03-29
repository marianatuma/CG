# Makefile for program source directory in GNU NLS utilities package.
# Copyright (C) 1995, 1996, 1997 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
# Copyright (C) 2004-2008 Rodney Dawes <dobey.pwns@gmail.com>
#
# This file may be copied and used freely without restrictions.  It may
# be used in projects which are not available under a GNU Public License,
# but which still want to provide support for the GNU gettext functionality.
#
# - Modified by Owen Taylor <otaylor@redhat.com> to use GETTEXT_PACKAGE
#   instead of PACKAGE and to look for po2tbl in ./ not in intl/
#
# - Modified by jacob berkman <jacob@ximian.com> to install
#   Makefile.in.in and po2tbl.sed.in for use with glib-gettextize
#
# - Modified by Rodney Dawes <dobey.pwns@gmail.com> for use with intltool
#
# We have the following line for use by intltoolize:
# INTLTOOL_MAKEFILE

GETTEXT_PACKAGE = glade
PACKAGE = glade
VERSION = 3.20.0

SHELL = /bin/bash

srcdir = .
top_srcdir = ..
top_builddir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datadir = ${datarootdir}
datarootdir = ${prefix}/share
libdir = ${exec_prefix}/lib
DATADIRNAME = share
itlocaledir = $(prefix)/$(DATADIRNAME)/locale
subdir = po
install_sh = ${SHELL} /home/mariana/Documentos/CG/glade-3.20.0/install-sh
# Automake >= 1.8 provides $(MKDIR_P).
# Until it can be supposed, use the safe fallback:
mkdir_p = $(install_sh) -d

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

GMSGFMT = /usr/bin/msgfmt
MSGFMT = /usr/bin/msgfmt
XGETTEXT = /usr/bin/xgettext
INTLTOOL_UPDATE = /usr/bin/intltool-update
INTLTOOL_EXTRACT = /usr/bin/intltool-extract
MSGMERGE = INTLTOOL_EXTRACT="$(INTLTOOL_EXTRACT)" XGETTEXT="$(XGETTEXT)" srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --dist
GENPOT   = INTLTOOL_EXTRACT="$(INTLTOOL_EXTRACT)" XGETTEXT="$(XGETTEXT)" srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --pot

ALL_LINGUAS = 

PO_LINGUAS=$(shell if test -r $(srcdir)/LINGUAS; then grep -v "^\#" $(srcdir)/LINGUAS; else echo "$(ALL_LINGUAS)"; fi)

USER_LINGUAS=$(shell if test -n "$(LINGUAS)"; then LLINGUAS="$(LINGUAS)"; ALINGUAS="$(ALL_LINGUAS)"; for lang in $$LLINGUAS; do if test -n "`grep \^$$lang$$ $(srcdir)/LINGUAS 2>/dev/null`" -o -n "`echo $$ALINGUAS|tr ' ' '\n'|grep \^$$lang$$`"; then printf "$$lang "; fi; done; fi)

USE_LINGUAS=$(shell if test -n "$(USER_LINGUAS)" -o -n "$(LINGUAS)"; then LLINGUAS="$(USER_LINGUAS)"; else if test -n "$(PO_LINGUAS)"; then LLINGUAS="$(PO_LINGUAS)"; else LLINGUAS="$(ALL_LINGUAS)"; fi; fi; for lang in $$LLINGUAS; do printf "$$lang "; done)

POFILES=$(shell LINGUAS="$(PO_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.po "; done)

DISTFILES = Makefile.in.in POTFILES.in $(POFILES)
EXTRA_DISTFILES = ChangeLog POTFILES.skip Makevars LINGUAS

POTFILES = \
	../data/glade.desktop.in.in \
	../data/glade.appdata.xml.in \
	../src/glade-close-button.c \
	../src/glade-window.c \
	../src/main.c \
	../src/glade.glade \
	../src/glade-preferences.glade \
	../src/glade-registration.c \
	../src/glade-registration.glade \
	../gladeui/glade-app.c \
	../gladeui/glade-base-editor.c \
	../gladeui/glade-builtins.c \
	../gladeui/glade-catalog.c \
	../gladeui/glade-clipboard.c \
	../gladeui/glade-command.c \
	../gladeui/glade-cursor.c \
	../gladeui/glade-debug.c \
	../gladeui/glade-design-layout.c \
	../gladeui/glade-design-view.c \
	../gladeui/glade-editor.c \
	../gladeui/glade-editor-property.c \
	../gladeui/glade-editor-skeleton.c \
	../gladeui/glade-editor-table.c \
	../gladeui/glade-inspector.c \
	../gladeui/glade-named-icon-chooser-dialog.c \
	../gladeui/glade-object-stub.c \
	../gladeui/glade-palette.c \
	../gladeui/glade-placeholder.c \
	../gladeui/glade-popup.c \
	../gladeui/glade-preview.c \
	../gladeui/glade-previewer.c \
	../gladeui/glade-preview-window.c \
	../gladeui/glade-project.c \
	../gladeui/glade-project-properties.c \
	../gladeui/glade-property.c \
	../gladeui/glade-property-class.c \
	../gladeui/glade-property-label.c \
	../gladeui/glade-property-shell.c \
	../gladeui/glade-signal.c \
	../gladeui/glade-signal-class.c \
	../gladeui/glade-signal-editor.c \
	../gladeui/glade-utils.c \
	../gladeui/glade-widget-action.c \
	../gladeui/glade-widget-adaptor.c \
	../gladeui/glade-widget.c \
	../gladeui/glade-xml-utils.c \
	../gladeui/icon-naming-spec.c \
	../gladeui/glade-adaptor-chooser.ui \
	../gladeui/glade-editor.ui \
	../gladeui/glade-project-properties.ui \
	../gladeui/glade-property-label.ui \
	../plugins/gtk+/glade-about-dialog-editor.c \
	../plugins/gtk+/glade-accels.c \
	../plugins/gtk+/glade-action-bar-editor.c \
	../plugins/gtk+/glade-action-editor.c \
	../plugins/gtk+/glade-activatable-editor.c \
	../plugins/gtk+/glade-app-chooser-button-editor.c \
	../plugins/gtk+/glade-app-chooser-widget-editor.c \
	../plugins/gtk+/glade-arrow-editor.c \
	../plugins/gtk+/glade-attributes.c \
	../plugins/gtk+/glade-box-editor.c \
	../plugins/gtk+/glade-button-editor.c \
	../plugins/gtk+/glade-cell-renderer-editor.c \
	../plugins/gtk+/glade-column-types.c \
	../plugins/gtk+/glade-combo-box-editor.c \
	../plugins/gtk+/glade-combo-box-text-editor.c \
	../plugins/gtk+/glade-entry-editor.c \
	../plugins/gtk+/glade-file-chooser-button-editor.c \
	../plugins/gtk+/glade-file-chooser-dialog-editor.c \
	../plugins/gtk+/glade-file-chooser-editor.c \
	../plugins/gtk+/glade-file-chooser-widget-editor.c \
	../plugins/gtk+/glade-fixed.c \
	../plugins/gtk+/glade-font-button-editor.c \
	../plugins/gtk+/glade-font-chooser-dialog-editor.c \
	../plugins/gtk+/glade-font-chooser-editor.c \
	../plugins/gtk+/glade-font-chooser-widget-editor.c \
	../plugins/gtk+/glade-grid-editor.c \
	../plugins/gtk+/glade-gtk-about-dialog.c \
	../plugins/gtk+/glade-gtk-action.c \
	../plugins/gtk+/glade-gtk-action-group.c \
	../plugins/gtk+/glade-gtk-action-widgets.c \
	../plugins/gtk+/glade-gtk-adjustment.c \
	../plugins/gtk+/glade-gtk-app-chooser-button.c \
	../plugins/gtk+/glade-gtk-app-chooser-widget.c \
	../plugins/gtk+/glade-gtk-arrow.c \
	../plugins/gtk+/glade-gtk-assistant.c \
	../plugins/gtk+/glade-gtk-box.c \
	../plugins/gtk+/glade-gtk-button.c \
	../plugins/gtk+/glade-gtk-cell-layout.c \
	../plugins/gtk+/glade-gtk-cell-renderer.c \
	../plugins/gtk+/glade-gtk-combo-box.c \
	../plugins/gtk+/glade-gtk-combo-box-text.c \
	../plugins/gtk+/glade-gtk-container.c \
	../plugins/gtk+/glade-gtk-dialog.c \
	../plugins/gtk+/glade-gtk-entry-buffer.c \
	../plugins/gtk+/glade-gtk-entry.c \
	../plugins/gtk+/glade-gtk-expander.c \
	../plugins/gtk+/glade-gtk-file-chooser-widget.c \
	../plugins/gtk+/glade-gtk-fixed-layout.c \
	../plugins/gtk+/glade-gtk-flow-box.c \
	../plugins/gtk+/glade-gtk-font-chooser-widget.c \
	../plugins/gtk+/glade-gtk-frame.c \
	../plugins/gtk+/glade-gtk-grid.c \
	../plugins/gtk+/glade-gtk-header-bar.c \
	../plugins/gtk+/glade-gtk-icon-factory.c \
	../plugins/gtk+/glade-gtk-icon-view.c \
	../plugins/gtk+/glade-gtk-image.c \
	../plugins/gtk+/glade-gtk-image-menu-item.c \
	../plugins/gtk+/glade-gtk-info-bar.c \
	../plugins/gtk+/glade-gtk-label.c \
	../plugins/gtk+/glade-gtk-level-bar.c \
	../plugins/gtk+/glade-gtk-list-box.c \
	../plugins/gtk+/glade-gtk-list-store.c \
	../plugins/gtk+/glade-gtk-menu-bar.c \
	../plugins/gtk+/glade-gtk-menu.c \
	../plugins/gtk+/glade-gtk-menu-item.c \
	../plugins/gtk+/glade-gtk-menu-shell.c \
	../plugins/gtk+/glade-gtk-menu-tool-button.c \
	../plugins/gtk+/glade-gtk-message-dialog.c \
	../plugins/gtk+/glade-gtk-notebook.c \
	../plugins/gtk+/glade-gtk-paned.c \
	../plugins/gtk+/glade-gtk-progress-bar.c \
	../plugins/gtk+/glade-gtk-radio-button.c \
	../plugins/gtk+/glade-gtk-radio-menu-item.c \
	../plugins/gtk+/glade-gtk-recent-chooser-menu.c \
	../plugins/gtk+/glade-gtk-recent-chooser-widget.c \
	../plugins/gtk+/glade-gtk-recent-file-filter.c \
	../plugins/gtk+/glade-gtk-scale.c \
	../plugins/gtk+/glade-gtk-scrollbar.c \
	../plugins/gtk+/glade-gtk-scrolled-window.c \
	../plugins/gtk+/glade-gtk-searchbar.c \
	../plugins/gtk+/glade-gtk-size-group.c \
	../plugins/gtk+/glade-gtk-spin-button.c \
	../plugins/gtk+/glade-gtk-stack.c \
	../plugins/gtk+/glade-gtk-switch.c \
	../plugins/gtk+/glade-gtk-table.c \
	../plugins/gtk+/glade-gtk-text-buffer.c \
	../plugins/gtk+/glade-gtk-text-tag-table.c \
	../plugins/gtk+/glade-gtk-text-view.c \
	../plugins/gtk+/glade-gtk-toolbar.c \
	../plugins/gtk+/glade-gtk-tool-button.c \
	../plugins/gtk+/glade-gtk-tool-item.c \
	../plugins/gtk+/glade-gtk-tool-item-group.c \
	../plugins/gtk+/glade-gtk-tool-palette.c \
	../plugins/gtk+/glade-gtk-tree-view.c \
	../plugins/gtk+/glade-gtk-viewport.c \
	../plugins/gtk+/glade-gtk-widget.c \
	../plugins/gtk+/glade-gtk-window.c \
	../plugins/gtk+/glade-header-bar-editor.c \
	../plugins/gtk+/glade-icon-factory-editor.c \
	../plugins/gtk+/glade-icon-sources.c \
	../plugins/gtk+/glade-icon-view-editor.c \
	../plugins/gtk+/glade-image-editor.c \
	../plugins/gtk+/glade-image-item-editor.c \
	../plugins/gtk+/glade-label-editor.c \
	../plugins/gtk+/glade-layout-editor.c \
	../plugins/gtk+/glade-level-bar-editor.c \
	../plugins/gtk+/glade-message-dialog-editor.c \
	../plugins/gtk+/glade-misc-editor.c \
	../plugins/gtk+/glade-model-data.c \
	../plugins/gtk+/glade-notebook-editor.c \
	../plugins/gtk+/glade-progress-bar-editor.c \
	../plugins/gtk+/glade-real-tree-view-editor.c \
	../plugins/gtk+/glade-recent-action-editor.c \
	../plugins/gtk+/glade-recent-chooser-dialog-editor.c \
	../plugins/gtk+/glade-recent-chooser-editor.c \
	../plugins/gtk+/glade-recent-chooser-menu-editor.c \
	../plugins/gtk+/glade-recent-chooser-widget-editor.c \
	../plugins/gtk+/glade-scale-button-editor.c \
	../plugins/gtk+/glade-scale-editor.c \
	../plugins/gtk+/glade-scrollable-editor.c \
	../plugins/gtk+/glade-scrollbar-editor.c \
	../plugins/gtk+/glade-scrolled-window-editor.c \
	../plugins/gtk+/glade-spin-button-editor.c \
	../plugins/gtk+/glade-store-editor.c \
	../plugins/gtk+/glade-string-list.c \
	../plugins/gtk+/glade-text-view-editor.c \
	../plugins/gtk+/glade-tool-button-editor.c \
	../plugins/gtk+/glade-tool-item-group-editor.c \
	../plugins/gtk+/glade-treeview-editor.c \
	../plugins/gtk+/glade-viewport-editor.c \
	../plugins/gtk+/glade-widget-editor.c \
	../plugins/gtk+/glade-window-editor.c \
	../plugins/gtk+/gtkunixprint.xml.in \
	../plugins/gtk+/gtk+.xml.in \
	../plugins/gtk+/glade-about-dialog-editor.ui \
	../plugins/gtk+/glade-action-bar-editor.ui \
	../plugins/gtk+/glade-action-editor.ui \
	../plugins/gtk+/glade-activatable-editor.ui \
	../plugins/gtk+/glade-app-chooser-button-editor.ui \
	../plugins/gtk+/glade-app-chooser-widget-editor.ui \
	../plugins/gtk+/glade-arrow-editor.ui \
	../plugins/gtk+/glade-box-editor.ui \
	../plugins/gtk+/glade-button-editor.ui \
	../plugins/gtk+/glade-combo-box-editor.ui \
	../plugins/gtk+/glade-combo-box-text-editor.ui \
	../plugins/gtk+/glade-entry-editor.ui \
	../plugins/gtk+/glade-file-chooser-button-editor.ui \
	../plugins/gtk+/glade-file-chooser-dialog-editor.ui \
	../plugins/gtk+/glade-file-chooser-editor.ui \
	../plugins/gtk+/glade-file-chooser-widget-editor.ui \
	../plugins/gtk+/glade-font-button-editor.ui \
	../plugins/gtk+/glade-font-chooser-dialog-editor.ui \
	../plugins/gtk+/glade-font-chooser-editor.ui \
	../plugins/gtk+/glade-grid-editor.ui \
	../plugins/gtk+/glade-header-bar-editor.ui \
	../plugins/gtk+/glade-icon-view-editor.ui \
	../plugins/gtk+/glade-image-editor.ui \
	../plugins/gtk+/glade-label-editor.ui \
	../plugins/gtk+/glade-layout-editor.ui \
	../plugins/gtk+/glade-level-bar-editor.ui \
	../plugins/gtk+/glade-message-dialog-editor.ui \
	../plugins/gtk+/glade-misc-editor.ui \
	../plugins/gtk+/glade-model-button-editor.ui \
	../plugins/gtk+/glade-notebook-editor.ui \
	../plugins/gtk+/glade-popover-editor.ui \
	../plugins/gtk+/glade-popover-menu-editor.ui \
	../plugins/gtk+/glade-progress-bar-editor.ui \
	../plugins/gtk+/glade-real-tree-view-editor.ui \
	../plugins/gtk+/glade-recent-action-editor.ui \
	../plugins/gtk+/glade-recent-chooser-dialog-editor.ui \
	../plugins/gtk+/glade-recent-chooser-editor.ui \
	../plugins/gtk+/glade-recent-chooser-menu-editor.ui \
	../plugins/gtk+/glade-recent-chooser-widget-editor.ui \
	../plugins/gtk+/glade-scale-button-editor.ui \
	../plugins/gtk+/glade-scale-editor.ui \
	../plugins/gtk+/glade-scrollable-editor.ui \
	../plugins/gtk+/glade-scrollbar-editor.ui \
	../plugins/gtk+/glade-scrolled-window-editor.ui \
	../plugins/gtk+/glade-spin-button-editor.ui \
	../plugins/gtk+/glade-stack-editor.ui \
	../plugins/gtk+/glade-stack-switcher-editor.ui \
	../plugins/gtk+/glade-text-view-editor.ui \
	../plugins/gtk+/glade-tool-button-editor.ui \
	../plugins/gtk+/glade-tool-palette-editor.ui \
	../plugins/gtk+/glade-viewport-editor.ui \
	../plugins/gtk+/glade-widget-editor.ui \
	../plugins/gtk+/glade-window-editor.ui

CATALOGS=$(shell LINGUAS="$(USE_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.gmo "; done)

.SUFFIXES:
.SUFFIXES: .po .pox .gmo .mo .msg .cat

AM_DEFAULT_VERBOSITY = 0
INTLTOOL_V_MSGFMT = $(INTLTOOL__v_MSGFMT_$(V))
INTLTOOL__v_MSGFMT_= $(INTLTOOL__v_MSGFMT_$(AM_DEFAULT_VERBOSITY))
INTLTOOL__v_MSGFMT_0 = @echo "  MSGFMT" $@;

.po.pox:
	$(MAKE) $(GETTEXT_PACKAGE).pot
	$(MSGMERGE) $< $(GETTEXT_PACKAGE).pot -o $*.pox

.po.mo:
	$(INTLTOOL_V_MSGFMT)$(MSGFMT) -o $@ $<

.po.gmo:
	$(INTLTOOL_V_MSGFMT)file=`echo $* | sed 's,.*/,,'`.gmo \
	  && rm -f $$file && $(GMSGFMT) -o $$file $<

.po.cat:
	sed -f ../intl/po2msg.sed < $< > $*.msg \
	  && rm -f $@ && gencat $@ $*.msg


all: all-yes

all-yes: $(CATALOGS)
all-no:

$(GETTEXT_PACKAGE).pot: $(POTFILES)
	$(GENPOT)

install: install-data
install-data: install-data-yes
install-data-no: all
install-data-yes: all
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  dir=$(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $$dir; \
	  if test -r $$lang.gmo; then \
	    $(INSTALL_DATA) $$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $$lang.gmo as $$dir/$(GETTEXT_PACKAGE).mo"; \
	  else \
	    $(INSTALL_DATA) $(srcdir)/$$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $(srcdir)/$$lang.gmo as" \
		 "$$dir/$(GETTEXT_PACKAGE).mo"; \
	  fi; \
	  if test -r $$lang.gmo.m; then \
	    $(INSTALL_DATA) $$lang.gmo.m $$dir/$(GETTEXT_PACKAGE).mo.m; \
	    echo "installing $$lang.gmo.m as $$dir/$(GETTEXT_PACKAGE).mo.m"; \
	  else \
	    if test -r $(srcdir)/$$lang.gmo.m ; then \
	      $(INSTALL_DATA) $(srcdir)/$$lang.gmo.m \
		$$dir/$(GETTEXT_PACKAGE).mo.m; \
	      echo "installing $(srcdir)/$$lang.gmo.m as" \
		   "$$dir/$(GETTEXT_PACKAGE).mo.m"; \
	    else \
	      true; \
	    fi; \
	  fi; \
	done

# Empty stubs to satisfy archaic automake needs
dvi info ctags tags CTAGS TAGS ID:

# Define this as empty until I found a useful application.
install-exec installcheck:

uninstall:
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo; \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo.m; \
	done

check: all $(GETTEXT_PACKAGE).pot
	rm -f missing notexist
	srcdir=$(srcdir) $(INTLTOOL_UPDATE) -m
	if [ -r missing -o -r notexist ]; then \
	  exit 1; \
	fi

mostlyclean:
	rm -f *.pox $(GETTEXT_PACKAGE).pot *.old.po cat-id-tbl.tmp
	rm -f .intltool-merge-cache

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES stamp-it
	rm -f *.mo *.msg *.cat *.cat.m *.gmo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f Makefile.in.in

distdir = ../$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir: $(DISTFILES)
	dists="$(DISTFILES)"; \
	extra_dists="$(EXTRA_DISTFILES)"; \
	for file in $$extra_dists; do \
	  test -f $(srcdir)/$$file && dists="$$dists $(srcdir)/$$file"; \
	done; \
	for file in $$dists; do \
	  test -f $$file || file="$(srcdir)/$$file"; \
	  ln $$file $(distdir) 2> /dev/null \
	    || cp -p $$file $(distdir); \
	done

update-po: Makefile
	$(MAKE) $(GETTEXT_PACKAGE).pot
	tmpdir=`pwd`; \
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  echo "$$lang:"; \
	  result="`$(MSGMERGE) -o $$tmpdir/$$lang.new.po $$lang`"; \
	  if $$result; then \
	    if cmp $(srcdir)/$$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	      rm -f $$tmpdir/$$lang.new.po; \
            else \
	      if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	        :; \
	      else \
	        echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	        rm -f $$tmpdir/$$lang.new.po; \
	        exit 1; \
	      fi; \
	    fi; \
	  else \
	    echo "msgmerge for $$lang.gmo failed!"; \
	    rm -f $$tmpdir/$$lang.new.po; \
	  fi; \
	done

Makefile POTFILES: stamp-it
	@if test ! -f $@; then \
	  rm -f stamp-it; \
	  $(MAKE) stamp-it; \
	fi

stamp-it: Makefile.in.in $(top_builddir)/config.status POTFILES.in
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/Makefile.in CONFIG_HEADERS= CONFIG_LINKS= \
	       $(SHELL) ./config.status

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
