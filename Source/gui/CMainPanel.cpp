//------------------------------------------------------------------------------
/*
  LayerEffects for JUCE

  Official project location:
  https://github.com/vinniefalco/LayerEffects

  ------------------------------------------------------------------------------

  License: MIT License (http://www.opensource.org/licenses/mit-license.php)
  Copyright (c) 2012 by Vinnie Falco

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/
//------------------------------------------------------------------------------

CMainPanel::CMainPanel ()
  : ResizableLayout (this)
  , TopLevelConstrainer (this)
{
  setOpaque (true);
  setSize (4 + 240 + 4 + 484 + 4, 4 + 360 + 4 + 120 + 4);

  Component* c;

  c = new COptionsPanel;
  c->setBounds (4, 4, 240, 484);
  addAndMakeVisible (c);
  addToLayout (c, anchorTopLeft, anchorBottomLeft);

  c = new CLayerGraphicsPreview;
  c->setBounds (248, 4, 484, 484);
  addAndMakeVisible (c);
  addToLayout (c, anchorTopLeft, anchorBottomRight);

  setMinimumSize (4+240+4+120+4, 4+360+4+120+4);

  m_options.dropShadow.size = 8;
  m_options.dropShadow.angle = 135;
  m_options.dropShadow.distance = 8;
}

CMainPanel::~CMainPanel()
{
  deleteAllChildren();
}

void CMainPanel::paint (Graphics& g)
{
  g.fillAll (Colours::grey);
}

void CMainPanel::onOptionsGeneral (Options::General options)
{
  m_options.general = options;

  vf::componentBroadcast (this, &CLayerGraphicsPreview::setOptions, &m_options, false);
}

void CMainPanel::onOptionsFill (Options::Fill options)
{
  m_options.fill = options;

  vf::componentBroadcast (this, &CLayerGraphicsPreview::setOptions, &m_options, false);
}

void CMainPanel::onOptionsDropShadow (Options::DropShadow options)
{
  m_options.dropShadow = options;

  vf::componentBroadcast (this, &CLayerGraphicsPreview::setOptions, &m_options, false);
}

void CMainPanel::onOptionsGradientOverlay (Options::GradientOverlay options)
{
  m_options.gradientOverlay = options;

  vf::componentBroadcast (this, &CLayerGraphicsPreview::setOptions, &m_options, false);
}

StringArray CMainPanel::getMenuBarNames()
{
  StringArray names;
  names.add (TRANS("File"));
  return names;
}

PopupMenu CMainPanel::getMenuForIndex (int topLevelMenuIndex, const String& menuName)
{
  PopupMenu menu;
  ApplicationCommandManager* commandManager = MainApp::getInstance().getCommandManager();

  switch (topLevelMenuIndex)
  {
  case 0:
    menu.addCommandItem (commandManager, StandardApplicationCommandIDs::quit);
    break;

  case 1:
    menu.addCommandItem (commandManager, MainApp::cmdAbout);
    break;
  };

  return menu;
}

void CMainPanel::menuItemSelected (int menuItemID, int topLevelMenuIndex)
{
}
