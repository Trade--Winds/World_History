## Sid Meier's Civilization 4
## Copyright Firaxis Games 2005
from CvPythonExtensions import *
import CvUtil
import ScreenInput
import CvScreenEnums

# globals
gc = CyGlobalContext()
ArtFileMgr = CyArtFileMgr()
localText = CyTranslator()

class CvEuroZoneScreen:

	def __init__(self):
		self.WIDGET_ID = "EuropeScreenWidget"
		self.nWidgetCount = 0

		self.UNIT_BUTTON_ID = 1
		self.UNIT_CARGO_BUTTON_ID = 2
		self.BUY_YIELD_BUTTON_ID = 3
		self.YIELD_CARGO_BUTTON_ID = 4
		self.BUY_UNIT_BUTTON_ID = 5
		self.DOCK_BUTTON_ID = 6
		self.SAIL_TO_NEW_WORLD = 7
		self.SAIL_TO_NEW_WORLD_WEST = 12
		self.SELL_ALL = 8
		self.LOAD_ALL = 9
		self.HELP_CROSS_RATE = 10
		self.TREASURY_ID = 11

	def getScreen(self):
		return CyGInterfaceScreen("EuropeScreen", CvScreenEnums.EURO_ZONE_SCREEN)

	def interfaceScreen(self):
	
		if ( CyGame().isPitbossHost() ):
			return
		#TKs ME
		#if gc.getPlayer(gc.getGame().getActivePlayer()).getParent() == PlayerTypes.NO_PLAYER:
			#return
		#TKe
		screen = self.getScreen()
		if screen.isActive():
			return

		screen.setRenderInterfaceOnly(True)
		screen.showScreen(PopupStates.POPUPSTATE_IMMEDIATE, False)

		self.XResolution = screen.getXResolution()
		self.YResolution = screen.getYResolution()

		self.Y_EXIT = self.YResolution - 36
		self.X_EXIT = self.XResolution - 30
		#TKs Med
		self.Y_RATES = (self.YResolution - 67) * 36 / 41
		#Tke
		self.IN_PORT_PANE_WIDTH = self.XResolution * 9 / 20
		self.X_IN_PORT = self.XResolution * 3 / 10
		self.PANE_HEIGHT = (self.YResolution - 55) * 31 / 40
		self.X_DOCK = self.XResolution * 7 / 10

		self.SHIP_ICON_SIZE = self.YResolution / 10
		self.CARGO_ICON_SIZE = self.XResolution / 25
		self.CARGO_SPACING  = self.CARGO_ICON_SIZE + 2

		self.H_TEXT_MARGIN = self.YResolution / 30
		self.W_TEXT_MARGIN = self.XResolution / 30

		self.X_RECRUIT_PANE = self.X_IN_PORT + self.IN_PORT_PANE_WIDTH + (self.W_TEXT_MARGIN / 2)
		self.PANE_WIDTH = self.XResolution * 7 / 20
		self.W_SLIDER = self.PANE_WIDTH - (self.W_TEXT_MARGIN * 2)
		self.H_LOADING_SLIDER = self.YResolution * 7 / 10
		self.Y_UPPER_EDGE = self.YResolution / 10
		self.RECRUIT_PANE_HEIGHT = self.YResolution / 7

		self.Y_RECRUIT_OFFSET = 25
		self.Y_TITLE = 4
		self.Y_BOUND = self.Y_UPPER_EDGE + (self.PANE_HEIGHT / 2)
		self.Y_DOCKS_OFFSET = 50
		self.H_DOCK = (self.PANE_HEIGHT - (self.H_TEXT_MARGIN * 2)) * 35 / 100
		#TradeScreen Code
		self.TRADE_SCREEN_SPICE_ROUTE_MARKET = CvUtil.findInfoTypeNum('TRADE_SCREEN_EURO_ZONE_MARKET')
		
		self.EUROPE_EAST = CvUtil.findInfoTypeNum('EUROPE_EAST')
		#self.EUROPE_WEST = CvUtil.findInfoTypeNum('EUROPE_WEST')

		# Set the background and exit button, and show the screen
		screen.setDimensions(0, 0, self.XResolution, self.YResolution)
		screen.showWindowBackground(False)
		
		screen.addDDSGFC("EuropeScreenBackground", ArtFileMgr.getInterfaceArtInfo("INTERFACE_SPICE_ROUTE_BACKGROUND").getPath(), 0, 0, self.XResolution, self.YResolution, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.addDDSGFC("TopPanel", ArtFileMgr.getInterfaceArtInfo("INTERFACE_SPICE_ROUTE_TITLE_BAR").getPath(), 0, 0, self.XResolution, 55, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.addDDSGFC("BottomPanel", ArtFileMgr.getInterfaceArtInfo("INTERFACE_SPICE_ROUTE_SCREEN_TAB_OFF").getPath(), 0, self.YResolution - 55, self.XResolution, 55, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.setText("EuropeScreenExitWidget", "Background", u"<font=4>" + localText.getText("TXT_KEY_PEDIA_SCREEN_EXIT", ()).upper() + "</font>", CvUtil.FONT_RIGHT_JUSTIFY, self.X_EXIT, self.Y_EXIT, 0, FontTypes.TITLE_FONT, WidgetTypes.WIDGET_CLOSE_SCREEN, -1, -1 )

		# Header...
		#TKs Med
		screen.setLabel("EuropeScreenWidgetHeader", "Background", u"<font=4b>" + localText.getText("TXT_KEY_SPICE_ROUTE_SCREEN_TITLE", ()).upper() + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.XResolution / 2, self.Y_TITLE, 0, FontTypes.TITLE_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1)

		# InBound
		screen.addDDSGFC("EuropeScreenInboundImage", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SHADOW_BOX").getPath(), - self.W_TEXT_MARGIN, self.Y_UPPER_EDGE, self.PANE_WIDTH, (self.PANE_HEIGHT - self.H_TEXT_MARGIN) / 2, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		szText = localText.changeTextColor(localText.getText("TXT_KEY_VOYAGING", ()).upper(), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
		screen.setLabel("EuropeScreenInboundText", "Background",  u"<font=4>" + szText + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, (self.PANE_WIDTH / 2), self.Y_UPPER_EDGE - (self.H_TEXT_MARGIN / 2), 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.addScrollPanel("InBoundList", u"", self.W_TEXT_MARGIN / 2, self.Y_UPPER_EDGE + self.H_TEXT_MARGIN, self.W_SLIDER, ((self.PANE_HEIGHT - self.H_TEXT_MARGIN) / 2) - (self.H_TEXT_MARGIN * 3), PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_GENERAL, -1, -1 )

		# OutBound
		screen.addDDSGFC("EuropeScreenOutboundImage", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SHADOW_BOX").getPath(), - self.W_TEXT_MARGIN, self.Y_BOUND, self.PANE_WIDTH, (self.PANE_HEIGHT - self.H_TEXT_MARGIN) / 2, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		szText = localText.changeTextColor(localText.getText("TXT_KEY_OUTBOUND", ()).upper(), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
		screen.setLabel("EuropeScreenOutboundText", "Background",  u"<font=4>" + szText + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, (self.PANE_WIDTH / 2), self.Y_BOUND - (self.H_TEXT_MARGIN / 2), 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, self.SAIL_TO_NEW_WORLD, -1 )
		screen.addScrollPanel("OutBoundList", u"", self.W_TEXT_MARGIN / 2, self.Y_BOUND + self.H_TEXT_MARGIN, self.W_SLIDER, ((self.PANE_HEIGHT - self.H_TEXT_MARGIN) / 2) - (self.H_TEXT_MARGIN * 3), PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1 )

		# In Port
		screen.addDDSGFC("EuropeScreenPortImage", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SHADOW_BOX").getPath(), self.X_IN_PORT, self.Y_UPPER_EDGE, self.IN_PORT_PANE_WIDTH, self.PANE_HEIGHT, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		szText = localText.changeTextColor(localText.getText("TXT_KEY_IN_PORT", ()).upper(), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
		screen.setLabel("EuropeScreenPortText", "Background",  u"<font=4>" + szText + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.X_IN_PORT + (self.IN_PORT_PANE_WIDTH / 2), self.Y_UPPER_EDGE - (self.H_TEXT_MARGIN / 2), 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.addScrollPanel("LoadingList", u"", self.X_IN_PORT + self.W_TEXT_MARGIN, self.Y_UPPER_EDGE, self.IN_PORT_PANE_WIDTH - (self.W_TEXT_MARGIN * 3 / 2), self.PANE_HEIGHT - (self.H_TEXT_MARGIN * 3), PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, -1, -1 )

		# Recruit
		#screen.addDDSGFC("EuropeScreenRecruitImage", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SHADOW_BOX").getPath(), self.X_IN_PORT + self.IN_PORT_PANE_WIDTH - (self.W_TEXT_MARGIN / 2), self.Y_UPPER_EDGE + (self.H_TEXT_MARGIN / 2) + self.Y_RECRUIT_OFFSET, self.PANE_WIDTH, self.RECRUIT_PANE_HEIGHT - (self.H_TEXT_MARGIN / 2), WidgetTypes.WIDGET_GENERAL, -1, -1 )
		#szText = localText.changeTextColor(localText.getText("TXT_KEY_HURRY_IMMIGRATION", ()).upper(), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
		#screen.setLabel("EuropeScreenRecruitText", "Background", u"<font=2>" + szText + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.X_DOCK + self.PANE_WIDTH / 2,  self.Y_UPPER_EDGE + self.Y_RECRUIT_OFFSET, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		#screen.addScrollPanel("RecruitList", u"", self.X_RECRUIT_PANE, self.Y_UPPER_EDGE + (self.H_TEXT_MARGIN / 2) + self.Y_RECRUIT_OFFSET, self.PANE_WIDTH, self.RECRUIT_PANE_HEIGHT, PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_DOCK, -1, -1 )

		# Dock
		#TKs Med
		iYModded = self.Y_UPPER_EDGE - 15
		screen.addDDSGFC("EuropeScreenDockImage", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SHADOW_BOX").getPath(), self.X_IN_PORT + self.IN_PORT_PANE_WIDTH - (self.W_TEXT_MARGIN / 2), iYModded + self.RECRUIT_PANE_HEIGHT + (self.H_TEXT_MARGIN / 2) + self.Y_DOCKS_OFFSET, self.PANE_WIDTH, self.H_DOCK, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.addScrollPanel("DockList", u"", self.X_IN_PORT + self.IN_PORT_PANE_WIDTH + (self.W_TEXT_MARGIN / 2), iYModded + self.RECRUIT_PANE_HEIGHT + (self.H_TEXT_MARGIN / 2) + self.Y_DOCKS_OFFSET, self.PANE_WIDTH - (self.W_TEXT_MARGIN * 7 / 2), self.H_DOCK - self.H_TEXT_MARGIN, PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_DOCK, -1, -1 )
		szText = localText.changeTextColor(localText.getText("TXT_KEY_EUROPE_SCREEN_DOCKS", ()).upper(), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
		screen.setLabel("EuropeScreenDockText", "Background", u"<font=4>" + szText + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.X_DOCK + self.PANE_WIDTH / 2, iYModded + self.RECRUIT_PANE_HEIGHT + self.Y_DOCKS_OFFSET - 5, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1)

		# Messages
		screen.addDDSGFC("EuropeScreenMessageImage", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SHADOW_BOX").getPath(), self.X_IN_PORT + self.IN_PORT_PANE_WIDTH - (self.W_TEXT_MARGIN / 2), iYModded + self.RECRUIT_PANE_HEIGHT + self.H_TEXT_MARGIN + self.H_DOCK + 60, self.PANE_WIDTH, self.H_DOCK, WidgetTypes.WIDGET_GENERAL, -1, -1 )
		screen.addListBoxGFC("MessageList", "", self.X_IN_PORT + self.IN_PORT_PANE_WIDTH, iYModded + self.RECRUIT_PANE_HEIGHT + self.H_TEXT_MARGIN + self.H_DOCK + 60, self.PANE_WIDTH - (self.W_TEXT_MARGIN * 3), self.H_DOCK, TableStyles.TABLE_STYLE_STANDARD)
		screen.enableSelect("MessageList", False)
		szText = localText.changeTextColor(localText.getText("TXT_KEY_EUROPE_TRANSACTIONS", ()).upper(), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
		screen.setLabel("EuropeScreenMessageText", "Background", u"<font=4>" + szText + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.X_DOCK + self.PANE_WIDTH / 2, iYModded + self.RECRUIT_PANE_HEIGHT + self.H_TEXT_MARGIN + self.H_DOCK + 40, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1)

		# Purchase
		if (gc.getPlayer(gc.getGame().getActivePlayer()).canTradeWithEurope()):
			screen.setImageButton("HireButton", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_PURCHASE_UNIT").getPath(), self.XResolution * 8 / 10, 65, self.CARGO_ICON_SIZE, self.CARGO_ICON_SIZE, WidgetTypes.WIDGET_GENERAL, self.BUY_UNIT_BUTTON_ID, -1)
			#Tke
			szText = localText.changeTextColor(localText.getText("TXT_KEY_HIRE", ()), gc.getInfoTypeForString("COLOR_FONT_CREAM"))
			screen.setText("HireButtonText", "Background", u"<font=4>" + szText + u"</font>", CvUtil.FONT_LEFT_JUSTIFY, (self.XResolution * 8 / 10) + (self.CARGO_ICON_SIZE), 60 + ((self.CARGO_ICON_SIZE * 1 / 2) - 10), 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, self.BUY_UNIT_BUTTON_ID, -1)
		#TKs
		self.TOTAL_CLOTH = 0
		
		
		if self.XResolution > 1600 and self.YResolution > 1024:
			SMALL_BUTTON_SIZE = 36
			MEDIUM_BUTTON_SIZE = 42
			LARGE_BUTTON_SIZE =	48
		elif self.XResolution > 1280 and self.YResolution > 800:
			SMALL_BUTTON_SIZE = 32
			MEDIUM_BUTTON_SIZE = 36
			LARGE_BUTTON_SIZE = 40
		else:
			SMALL_BUTTON_SIZE = 24
			MEDIUM_BUTTON_SIZE = 32
			LARGE_BUTTON_SIZE = 36
		STACK_BAR_HEIGHT = int((2.7 * self.YResolution) / 100)	
		ScrollButtonSize = LARGE_BUTTON_SIZE
			
		if (gc.getPlayer(gc.getGame().getActivePlayer()).getHasTradeRouteType(TradeRouteTypes.TRADE_ROUTE_SILK_ROAD)):
			screen.setImageButton("ImmigratioinScreen",ArtFileMgr.getInterfaceArtInfo("INTERFACE_IMMIGRATION").getPath(), (self.XResolution * 35 / 100) - (ScrollButtonSize / 2), (STACK_BAR_HEIGHT / 2) - (ScrollButtonSize / 3), ScrollButtonSize, ScrollButtonSize, WidgetTypes.WIDGET_ACTION, gc.getControlInfo(ControlTypes.CONTROL_IMMIGRATION_SCREEN).getActionInfoIndex(), -1)
			screen.setImageButton("SilkRoadScreen",ArtFileMgr.getInterfaceArtInfo("INTERFACE_SILK_ROAD").getPath(), (self.XResolution * 65 / 100) - (ScrollButtonSize / 2), (STACK_BAR_HEIGHT / 2) - (ScrollButtonSize / 3), ScrollButtonSize, ScrollButtonSize, WidgetTypes.WIDGET_ACTION, gc.getControlInfo(ControlTypes.CONTROL_SILK_ROAD_SCREEN).getActionInfoIndex(), -1)
		else:
			screen.setImageButton("ImmigratioinScreen",ArtFileMgr.getInterfaceArtInfo("INTERFACE_IMMIGRATION").getPath(), (self.XResolution * 65 / 100) - (ScrollButtonSize / 2), (STACK_BAR_HEIGHT / 2) - (ScrollButtonSize / 3), ScrollButtonSize, ScrollButtonSize, WidgetTypes.WIDGET_ACTION, gc.getControlInfo(ControlTypes.CONTROL_IMMIGRATION_SCREEN).getActionInfoIndex(), -1)
		
		# draw the contents
		self.drawContents()

	def drawContents(self):
		
		player = gc.getPlayer(gc.getGame().getActivePlayer())
		playerEurope = gc.getPlayer(player.getParent())
		
		self.deleteAllWidgets()

		screen = self.getScreen()
		#TKs Med
		#screen.setLabel("EuropeScreenWidgetHeader", "Background", u"<font=4b>" + localText.getText("TXT_KEY_EUROPE_SCREEN_TITLE", ()).upper() + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.XResolution / 2, self.Y_TITLE, 0, FontTypes.TITLE_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1)
		screen.setLabel(self.getNextWidgetName(), "Background", u"<font=4>" + localText.getText("TXT_KEY_FINANCIAL_ADVISOR_TREASURY", (player.getGold(), )).upper() + u"</font>", CvUtil.FONT_LEFT_JUSTIFY, self.W_TEXT_MARGIN, self.Y_EXIT, 0, FontTypes.TITLE_FONT, WidgetTypes.WIDGET_GENERAL, self.TREASURY_ID, -1 )
		screen.setLabel(self.getNextWidgetName(), "Background", u"<font=4>" + localText.getText("TXT_KEY_MISC_TAX_RATE", (player.getTaxRate(), )) + u"</font>", CvUtil.FONT_LEFT_JUSTIFY, self.W_TEXT_MARGIN, self.Y_TITLE, 0, FontTypes.TITLE_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1 )

		EuropeUnitsList = []
		InboundUnitsList = []
		OutboundUnitsList = []
		(unit, iter) = player.firstUnit()
		while (unit):
			if (not unit.isCargo() and not unit.isDelayedDeath()):
				if (unit.getUnitTravelState() == UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE):
					EuropeUnitsList.append(unit)
				elif (unit.getUnitTravelState() == UnitTravelStates.UNIT_TRAVEL_STATE_TO_SPICE_ROUTE):
					InboundUnitsList.append(unit)
				if (unit.getUnitTravelState() == UnitTravelStates.UNIT_TRAVEL_STATE_FROM_SPICE_ROUTE):
					OutboundUnitsList.append(unit)
			(unit, iter) = player.nextUnit(iter)

		# Units
		ShipPanelWidth = self.IN_PORT_PANE_WIDTH - (self.W_TEXT_MARGIN * 3)			
		ShipPanelHight = self.YResolution / 10
		if (ShipPanelHight < 90):
			ShipPanelHight = 90
		yLocation_InPort = (len(EuropeUnitsList) - 1) * (ShipPanelHight + (ShipPanelHight / 3))
		yLocation_ToEurope = 0
		yLocation_FromEurope = 0
		yCenterCorrection = (self.SHIP_ICON_SIZE / 2) - (self.CARGO_ICON_SIZE / 2)

		for unit in EuropeUnitsList:

			szText = u"<font=3>" + unit.getName() + u"</font>"
			szShipPane = self.getNextWidgetName()
			screen.attachPanelAt("LoadingList", szShipPane, "", "", True, False, PanelStyles.PANEL_STYLE_EMPTY, 0, yLocation_InPort + self.SHIP_ICON_SIZE, ShipPanelWidth, ShipPanelHight + (ShipPanelHight / 3), WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), -1)

			screen.addDDSGFCAt(self.getNextWidgetName(), "LoadingList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_IN_PORT_BOX").getPath(), 0, yLocation_InPort + self.SHIP_ICON_SIZE, ShipPanelWidth, ShipPanelHight, WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), -1, False)
			screen.setLabelAt(self.getNextWidgetName(), szShipPane, "<font=3>" + unit.getName().upper() + "</font>", CvUtil.FONT_RIGHT_JUSTIFY, ShipPanelWidth - (self.CARGO_SPACING), self.CARGO_ICON_SIZE * 1 / 3, -0.1, FontTypes.SMALL_FONT, WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), unit.getID())

			for i in range(unit.cargoSpace()):
				screen.addDDSGFCAt(self.getNextWidgetName(), "LoadingList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_BOX_CARGO").getPath(), ShipPanelWidth - ((self.CARGO_SPACING * 2 / 3) * (i + 2)) - (self.CARGO_SPACING / 4), yLocation_InPort + self.SHIP_ICON_SIZE + (ShipPanelHight / 2) - (self.CARGO_ICON_SIZE / 6), self.CARGO_ICON_SIZE * 2 / 3, self.CARGO_ICON_SIZE * 2 / 3, WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), -1, False)

			YieldOnBoard = False
			iCargoCount = 0
			plot = unit.plot()
			for i in range(plot.getNumUnits()):
				loopUnit = plot.getUnit(i)
				transportUnit = loopUnit.getTransportUnit()
				if (not transportUnit.isNone() and transportUnit.getID() == unit.getID() and transportUnit.getOwner() == unit.getOwner()):
					if loopUnit.isGoods():
						szText = u"<font=2>%s</font>" % loopUnit.getYieldStored()
						iWidgetId = self.YIELD_CARGO_BUTTON_ID
						YieldOnBoard = True
					else:
						szText = ""
						iWidgetId = self.UNIT_CARGO_BUTTON_ID

					screen.addDragableButtonAt("LoadingList", self.getNextWidgetName(), loopUnit.getButton(), "", ShipPanelWidth - ((self.CARGO_SPACING * 2 / 3) * (iCargoCount + 2)) - (self.CARGO_SPACING / 4), yLocation_InPort + self.SHIP_ICON_SIZE + (ShipPanelHight / 2) - (self.CARGO_ICON_SIZE / 6), self.CARGO_ICON_SIZE * 2 / 3, self.CARGO_ICON_SIZE * 2 / 3, WidgetTypes.WIDGET_SHIP_CARGO, loopUnit.getID(), transportUnit.getID(), ButtonStyles.BUTTON_STYLE_LABEL)
					screen.setLabelAt( self.getNextWidgetName(), "LoadingList", szText, CvUtil.FONT_LEFT_JUSTIFY, ShipPanelWidth - ((self.CARGO_SPACING * 2 / 3) * (iCargoCount + 2)) - (self.CARGO_SPACING / 4), yLocation_InPort + self.SHIP_ICON_SIZE + ShipPanelHight - 10, -0.1, FontTypes.SMALL_FONT, WidgetTypes.WIDGET_SHIP_CARGO, loopUnit.getID(), transportUnit.getID())
					iCargoCount = iCargoCount + 1

			if (YieldOnBoard):
				screen.setImageButtonAt(self.getNextWidgetName(), "LoadingList", gc.getActionInfo(gc.getInfoTypeForString("COMMAND_CHOOSE_TRADE_ROUTES")).getButton(), ShipPanelWidth - (self.CARGO_ICON_SIZE * 2 / 2), yLocation_InPort + self.SHIP_ICON_SIZE + (self.CARGO_ICON_SIZE * 3 / 4), self.CARGO_ICON_SIZE * 3 / 2, self.CARGO_ICON_SIZE * 3 / 2, WidgetTypes.WIDGET_GENERAL, self.SELL_ALL, unit.getID())
			
			if (not unit.isFull() and player.getNumEuropeUnits() > 0):
				screen.setImageButtonAt(self.getNextWidgetName(), "LoadingList", gc.getActionInfo(gc.getInfoTypeForString("COMMAND_LOAD_CARGO")).getButton(), ShipPanelWidth - (self.CARGO_ICON_SIZE * 2 / 2), yLocation_InPort + self.SHIP_ICON_SIZE - (self.CARGO_ICON_SIZE * 3 / 8), self.CARGO_ICON_SIZE * 3 / 2, self.CARGO_ICON_SIZE * 3 / 2, WidgetTypes.WIDGET_GENERAL, self.LOAD_ALL, unit.getID())
			#TKs Med in port
			UnitInfo = gc.getUnitInfo(unit.getUnitType())
			iProfession = unit.getProfession()
			if unit.getDomainType() == DomainTypes.DOMAIN_LAND:
				screen.addDragableButtonAt("LoadingList", self.getNextWidgetName(), UnitInfo.getArtInfo(0, iProfession).getFullLengthIcon(), "", self.RECRUIT_PANE_HEIGHT  * 2 / 3, yLocation_InPort + self.RECRUIT_PANE_HEIGHT - 20, self.RECRUIT_PANE_HEIGHT  * 1 / 3, self.RECRUIT_PANE_HEIGHT * 2 / 3, WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), -1, ButtonStyles.BUTTON_STYLE_LABEL)
			else:
				screen.addDragableButtonAt("LoadingList", self.getNextWidgetName(), unit.getFullLengthIcon(), "", 0, yLocation_InPort, self.SHIP_ICON_SIZE * 2, self.SHIP_ICON_SIZE * 2, WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), -1, ButtonStyles.BUTTON_STYLE_LABEL)
			#Tke
#			screen.setImageButtonAt(self.getNextWidgetName(), "LoadingList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_SAIL").getPath(), - (self.CARGO_ICON_SIZE / 3) + 4, yLocation_InPort + (self.SHIP_ICON_SIZE * 2) - (self.CARGO_ICON_SIZE * 3 / 4), self.CARGO_ICON_SIZE * 3 / 2, self.CARGO_ICON_SIZE * 3 / 2, WidgetTypes.WIDGET_GENERAL, self.SAIL_TO_NEW_WORLD, unit.getID())
			if (unit.canSailEurope(self.EUROPE_EAST)):
				if gc.getCivilizationInfo(player.getCivilizationType()).isWaterStart():
					screen.setImageButtonAt(self.getNextWidgetName(), "LoadingList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_LEAVE_PORT").getPath(), - (self.CARGO_ICON_SIZE / 3) + 4, yLocation_InPort + (self.SHIP_ICON_SIZE * 2) - (self.CARGO_ICON_SIZE * 3 / 4), self.CARGO_ICON_SIZE * 3 / 2, self.CARGO_ICON_SIZE * 3 / 2, WidgetTypes.WIDGET_GENERAL, self.SAIL_TO_NEW_WORLD, unit.getID())
				else:
					screen.setImageButtonAt(self.getNextWidgetName(), "LoadingList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_LEAVE_PORT").getPath(), - (self.CARGO_ICON_SIZE / 3) + 4, yLocation_InPort + (self.SHIP_ICON_SIZE * 2) - (self.CARGO_ICON_SIZE * 3 / 4), self.CARGO_ICON_SIZE * 3 / 2, self.CARGO_ICON_SIZE * 3 / 2, WidgetTypes.WIDGET_GENERAL, self.SAIL_TO_NEW_WORLD, unit.getID())
			#if (unit.canSailEurope(self.EUROPE_WEST)):
			#	screen.setImageButtonAt(self.getNextWidgetName(), "LoadingList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_LEAVE_PORT").getPath(), - (self.CARGO_ICON_SIZE / 3) + 4, yLocation_InPort + (self.SHIP_ICON_SIZE / 2), self.CARGO_ICON_SIZE * 3 / 2, self.CARGO_ICON_SIZE * 3 / 2, WidgetTypes.WIDGET_GENERAL, self.SAIL_TO_NEW_WORLD_WEST, unit.getID())
			#yLocation_InPort -= ShipPanelHight + (ShipPanelHight / 3)

		ShipPanelHight = self.YResolution / 12

		for unit in InboundUnitsList:
		
			szText = localText.getText("TXT_KEY_ARRIVALS_IN", (unit.getName(), unit.getUnitTravelTimer()))

			screen.addDDSGFCAt(self.getNextWidgetName(), "InBoundList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_IN_BOUND_BOX").getPath(), 0, yLocation_ToEurope + (self.SHIP_ICON_SIZE / 3), self.W_SLIDER - self.W_TEXT_MARGIN, self.SHIP_ICON_SIZE, WidgetTypes.WIDGET_GENERAL, -1, unit.getID(), False)
			screen.setLabelAt( self.getNextWidgetName(), "InBoundList", "<font=2>" + unit.getName().upper() + " : " + szText.upper() + "</font>", CvUtil.FONT_LEFT_JUSTIFY, 20 , yLocation_ToEurope + (self.SHIP_ICON_SIZE / 3) + ShipPanelHight, -0.1, FontTypes.SMALL_FONT, WidgetTypes.WIDGET_GENERAL, -1, unit.getID())

			for i in range(unit.cargoSpace()):
				screen.addDDSGFCAt(self.getNextWidgetName(), "InBoundList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_BOX_CARGO").getPath(), self.W_SLIDER - (self.W_TEXT_MARGIN * 2) - ((self.CARGO_SPACING / 2) * (i)), yLocation_ToEurope + (self.SHIP_ICON_SIZE / 3) + (self.SHIP_ICON_SIZE / 2) - (self.CARGO_ICON_SIZE/4), self.CARGO_ICON_SIZE / 2, self.CARGO_ICON_SIZE / 2, WidgetTypes.WIDGET_SHIP_CARGO, unit.getID(), -1, False)

			iCargoCount = 0
			plot = unit.plot()
			for i in range(plot.getNumUnits()):
				loopUnit = plot.getUnit(i)
				transportUnit = loopUnit.getTransportUnit()
				if (not transportUnit.isNone() and transportUnit.getID() == unit.getID() and transportUnit.getOwner() == unit.getOwner()):
					screen.setImageButtonAt( self.getNextWidgetName(), "InBoundList", loopUnit.getButton(), self.W_SLIDER - (self.W_TEXT_MARGIN * 2) - ((self.CARGO_SPACING / 2) * (iCargoCount)), yLocation_ToEurope + (self.SHIP_ICON_SIZE / 3) + (self.SHIP_ICON_SIZE / 2) - (self.CARGO_ICON_SIZE / 4), self.CARGO_ICON_SIZE / 2, self.CARGO_ICON_SIZE / 2, WidgetTypes.WIDGET_GENERAL, -1, -1)
					iCargoCount += 1
			#TKs Med inBound
			if unit.getDomainType() == DomainTypes.DOMAIN_LAND:
				screen.addDDSGFCAt(self.getNextWidgetName(), "InBoundList", unit.getFullLengthIcon(), self.RECRUIT_PANE_HEIGHT * 2 / 3, yLocation_ToEurope + 20, self.RECRUIT_PANE_HEIGHT  * 1 / 3, self.RECRUIT_PANE_HEIGHT * 2 / 3, WidgetTypes.WIDGET_GENERAL, -1, -1, False)
			#TKe
			else:
				screen.addDDSGFCAt(self.getNextWidgetName(), "InBoundList", unit.getFullLengthIcon(), 0, yLocation_ToEurope - (self.SHIP_ICON_SIZE / 3), self.SHIP_ICON_SIZE * 4 / 3, self.SHIP_ICON_SIZE * 4 / 3, WidgetTypes.WIDGET_GENERAL, -1, -1, False)
			yLocation_ToEurope += ShipPanelHight + (self.H_TEXT_MARGIN)

		screen.addScrollPanel("OutBoundList", u"", self.W_TEXT_MARGIN / 2, self.Y_BOUND + self.H_TEXT_MARGIN, self.W_SLIDER, ((self.PANE_HEIGHT - self.H_TEXT_MARGIN) / 2) - (self.H_TEXT_MARGIN * 3), PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1 )
		for unit in OutboundUnitsList:
			szText = localText.getText("TXT_KEY_ARRIVALS_IN", (unit.getName(), unit.getUnitTravelTimer()))

			screen.addDDSGFCAt(self.getNextWidgetName(), "OutBoundList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_OUT_BOUND_BOX").getPath(), 0, yLocation_FromEurope + (self.SHIP_ICON_SIZE / 3), self.W_SLIDER - self.W_TEXT_MARGIN, self.SHIP_ICON_SIZE, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1, False)
			screen.setLabelAt( self.getNextWidgetName(), "OutBoundList", "<font=2>" + unit.getName().upper() + " : " + szText.upper() + "</font>", CvUtil.FONT_RIGHT_JUSTIFY, self.W_SLIDER - self.W_TEXT_MARGIN - 10, yLocation_FromEurope + (self.SHIP_ICON_SIZE / 3) + ShipPanelHight, -0.1, FontTypes.SMALL_FONT, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1)

			for i in range(unit.cargoSpace()):
				screen.addDDSGFCAt(self.getNextWidgetName(), "OutBoundList", ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_BOX_CARGO").getPath(), self.W_SLIDER - (self.W_TEXT_MARGIN * 2) - ((self.CARGO_SPACING / 2) * (i)), yLocation_FromEurope + (self.SHIP_ICON_SIZE / 3) + (self.SHIP_ICON_SIZE / 2) - (self.CARGO_ICON_SIZE/4), self.CARGO_ICON_SIZE / 2, self.CARGO_ICON_SIZE / 2, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1, False)

			iCargoCount = 0
			plot = unit.plot()
			for i in range(plot.getNumUnits()):
				loopUnit = plot.getUnit(i)
				transportUnit = loopUnit.getTransportUnit()
				if (not transportUnit.isNone() and transportUnit.getID() == unit.getID() and transportUnit.getOwner() == unit.getOwner()):
					screen.setImageButtonAt( self.getNextWidgetName(), "OutBoundList", loopUnit.getButton(), self.W_SLIDER - (self.W_TEXT_MARGIN * 2) - ((self.CARGO_SPACING / 2) * iCargoCount), yLocation_FromEurope + (self.SHIP_ICON_SIZE / 3) + (self.SHIP_ICON_SIZE / 2) - (self.CARGO_ICON_SIZE / 4), self.CARGO_ICON_SIZE / 2, self.CARGO_ICON_SIZE / 2, WidgetTypes.WIDGET_GENERAL, -1, -1)
					iCargoCount += 1
			#TKs MEd outbound
			if unit.getDomainType() == DomainTypes.DOMAIN_LAND:
				screen.addDDSGFCAt( self.getNextWidgetName(), "OutBoundList", unit.getFullLengthIcon(), self.RECRUIT_PANE_HEIGHT  * 2 / 3, yLocation_FromEurope + 20, self.RECRUIT_PANE_HEIGHT  * 1 / 3, self.RECRUIT_PANE_HEIGHT * 2 / 3, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1, False)
			#Tke
			else:
				screen.addDDSGFCAt( self.getNextWidgetName(), "OutBoundList", unit.getFullLengthIcon(), 0, yLocation_FromEurope - (self.SHIP_ICON_SIZE / 3), self.SHIP_ICON_SIZE * 4 / 3, self.SHIP_ICON_SIZE * 4 / 3, WidgetTypes.WIDGET_SAIL, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_EUROPE, -1, False)
			yLocation_FromEurope += ShipPanelHight + (self.H_TEXT_MARGIN)


		# Units waiting on Docks
		XLocation = 0
		YLocation = 0

		screen.addScrollPanel("DockList", u"", self.X_IN_PORT + self.IN_PORT_PANE_WIDTH + (self.W_TEXT_MARGIN / 2), self.Y_UPPER_EDGE + self.RECRUIT_PANE_HEIGHT + (self.H_TEXT_MARGIN / 2) + self.Y_DOCKS_OFFSET, self.PANE_WIDTH - (self.W_TEXT_MARGIN * 7 / 2), self.H_DOCK - self.H_TEXT_MARGIN, PanelStyles.PANEL_STYLE_MAIN, false, WidgetTypes.WIDGET_DOCK, -1, -1 )
		for i in range(player.getNumEuropeUnits()):
			loopUnit = player.getEuropeUnit(i)
			if (loopUnit.getUnitTravelState() == UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE):
				screen.addDragableButtonAt("DockList", self.getNextWidgetName(), loopUnit.getFullLengthIcon(), "", XLocation, YLocation, self.CARGO_ICON_SIZE, self.CARGO_ICON_SIZE * 2, WidgetTypes.WIDGET_DOCK, loopUnit.getID(), -1, ButtonStyles.BUTTON_STYLE_LABEL )
				if ((i + 1) % 5) == 0:
					XLocation = 0
					YLocation += (self.CARGO_ICON_SIZE * 2)
				else:
					XLocation += self.CARGO_ICON_SIZE

		# Units to Recruit
#		RecruitPaneWidth = self.XResolution - self.X_RECRUIT_PANE
#		for i in range (gc.getDefineINT("DOCKS_NEXT_UNITS")):
#			if player.getDocksNextUnit(i) != UnitTypes.NO_UNIT:
#				UnitInfo = gc.getUnitInfo(player.getDocksNextUnit(i))
#				iProfession = UnitInfo.getDefaultProfession()
#				#Androrc UnitArtStyles
##				screen.setImageButtonAt( self.getNextWidgetName(), "RecruitList", UnitInfo.getArtInfo(0, iProfession).getFullLengthIcon(), i * RecruitPaneWidth / gc.getDefineINT("DOCKS_NEXT_UNITS"), self.RECRUIT_PANE_HEIGHT / 16, self.RECRUIT_PANE_HEIGHT  * 1 / 3, self.RECRUIT_PANE_HEIGHT * 2 / 3, WidgetTypes.WIDGET_PLAYER_HURRY, gc.getInfoTypeForString("HURRY_IMMIGRANT"), i)
#				iUnitArtStyle = gc.getCivilizationInfo(player.getCivilizationType()).getUnitArtStyleType()
#				screen.setImageButtonAt( self.getNextWidgetName(), "RecruitList", UnitInfo.getUnitArtStylesArtInfo(0, iProfession, iUnitArtStyle).getFullLengthIcon(), i * RecruitPaneWidth / gc.getDefineINT("DOCKS_NEXT_UNITS"), self.RECRUIT_PANE_HEIGHT / 16, self.RECRUIT_PANE_HEIGHT  * 1 / 3, self.RECRUIT_PANE_HEIGHT * 2 / 3, WidgetTypes.WIDGET_PLAYER_HURRY, gc.getInfoTypeForString("HURRY_IMMIGRANT"), i)
#				#Androrc End
				
		# Trade Messages
		screen.clearListBoxGFC("MessageList")
		for i in range(player.getNumTradeMessages()):
			screen.prependListBoxString("MessageList", player.getTradeMessage(i), WidgetTypes.WIDGET_GENERAL, -1, -1, CvUtil.FONT_LEFT_JUSTIFY )

		# Yield Rates
		YieldList = []
		
		iDiscoverCount = 0
		pPlayer = gc.getPlayer(gc.getGame().getActivePlayer())
		for iYield in range(YieldTypes.NUM_YIELD_TYPES):
			kYield = gc.getYieldInfo(iYield)
			if kYield.isCargo():
				if (pPlayer.canUnitBeTraded(iYield, UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE, UnitTypes.NO_UNIT)):
					YieldList.append(iYield)
				else:
					iDiscoverCount += 1
		WidthMod = 33
		BoxWithMod = -3
		iDiscoverCount = len(YieldList) + iDiscoverCount
		YieldAreaWidth = (self.XResolution / WidthMod) * len(YieldList)
		
		xLocation = (self.XResolution / 2) - (YieldAreaWidth / 2) - 30
		BoxSize = self.XResolution / (iDiscoverCount + BoxWithMod)
		
		MilitaryYieldAreaWidth = (self.XResolution / WidthMod) * iDiscoverCount
		xMilitaryLocation = (self.XResolution / 2) - (YieldAreaWidth / 2) - 30
		MilitaryBoxSize = self.XResolution / (iDiscoverCount + BoxWithMod)
		#TKs Med
		Military_Y_RATES = ((self.YResolution - 55) * 36 / 39) + 2
		
		for iYield in YieldList:
			kYield = gc.getYieldInfo(iYield)
			iSellPrice = playerEurope.getYieldSellPrice(iYield, UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE)
			iBuyPrice = playerEurope.getYieldBuyPrice(iYield, UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE)
			
			if (kYield.isMilitary()):
				screen.addDDSGFC(self.getNextWidgetName(), ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_BOX_PRICE").getPath(), xMilitaryLocation - MilitaryBoxSize, Military_Y_RATES, MilitaryBoxSize, MilitaryBoxSize, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, iYield, -1 )
				screen.addDragableButton(self.getNextWidgetName(), gc.getYieldInfo(iYield).getIcon(), "", xMilitaryLocation - MilitaryBoxSize + (MilitaryBoxSize / 8), Military_Y_RATES + (MilitaryBoxSize / 3), MilitaryBoxSize * 3 / 4, MilitaryBoxSize * 3 / 4, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, iYield, -1, ButtonStyles.BUTTON_STYLE_IMAGE )
				szPrices = u"<font=3>%d/%d</font>" % (iBuyPrice, iSellPrice)
				if not player.isYieldEuropeTradable(iYield):
					szPrices = u"<color=255,0,0>" + szPrices + u"</color>"
				screen.setLabel(self.getNextWidgetName(), "Background", szPrices, CvUtil.FONT_CENTER_JUSTIFY, xMilitaryLocation - (MilitaryBoxSize / 2), Military_Y_RATES, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, iYield, -1)
	
				xMilitaryLocation += MilitaryBoxSize
			else:	
				screen.addDDSGFC(self.getNextWidgetName(), ArtFileMgr.getInterfaceArtInfo("INTERFACE_EUROPE_BOX_PRICE").getPath(), xLocation - BoxSize, self.Y_RATES - 10, BoxSize, BoxSize, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, iYield, -1 )
				screen.addDragableButton(self.getNextWidgetName(), gc.getYieldInfo(iYield).getIcon(), "", xLocation - BoxSize + (BoxSize / 8), self.Y_RATES + (BoxSize / 3) - 10, BoxSize * 3 / 4, BoxSize * 3 / 4, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, iYield, -1, ButtonStyles.BUTTON_STYLE_IMAGE )
				szPrices = u"<font=3>%d/%d</font>" % (iBuyPrice, iSellPrice)
				if not player.isYieldEuropeTradable(iYield):
					szPrices = u"<color=255,0,0>" + szPrices + u"</color>"
				screen.setLabel(self.getNextWidgetName(), "Background", szPrices, CvUtil.FONT_CENTER_JUSTIFY, xLocation - (BoxSize / 2), self.Y_RATES - 10, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_MOVE_CARGO_TO_TRANSPORT, iYield, -1)
	
				xLocation += BoxSize
			#TKe
		#szWidget = self.getNextWidgetName()
		#screen.addStackedBarGFC(szWidget, self.XResolution * 3 / 8, self.Y_EXIT, self.XResolution / 4, 30, InfoBarTypes.NUM_INFOBAR_TYPES, WidgetTypes.WIDGET_GENERAL, self.HELP_CROSS_RATE, -1)
		#screen.setStackedBarColors(szWidget, InfoBarTypes.INFOBAR_STORED, gc.getInfoTypeForString("COLOR_GREAT_PEOPLE_STORED"))
		#screen.setStackedBarColors(szWidget, InfoBarTypes.INFOBAR_RATE, gc.getInfoTypeForString("COLOR_GREAT_PEOPLE_RATE"))
		#screen.setStackedBarColors(szWidget, InfoBarTypes.INFOBAR_RATE_EXTRA, gc.getInfoTypeForString("COLOR_EMPTY"))
		#screen.setStackedBarColors(szWidget, InfoBarTypes.INFOBAR_EMPTY, gc.getInfoTypeForString("COLOR_EMPTY"))
		#fStoredPercent = float(player.getCrossesStored()) / float(player.immigrationThreshold())
		#screen.setBarPercentage(szWidget, InfoBarTypes.INFOBAR_STORED, fStoredPercent)
		#if (fStoredPercent < 1.0):
		#	fRatePercent = float(player.getYieldRate(YieldTypes.YIELD_CROSSES)) / float(player.immigrationThreshold()) / (1 - fStoredPercent)
		#	screen.setBarPercentage(szWidget, InfoBarTypes.INFOBAR_RATE, fRatePercent)
		#screen.setLabel(self.getNextWidgetName(), "", u"<font=3>" + localText.getText("TXT_KEY_IMMIGRATION_BAR", (player.getCrossesStored(), player.immigrationThreshold(), gc.getYieldInfo(YieldTypes.YIELD_CROSSES).getChar())) + u"</font>", CvUtil.FONT_CENTER_JUSTIFY, self.XResolution / 2, self.Y_EXIT + 3, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, self.HELP_CROSS_RATE, -1)

		return 0

	def getNextWidgetName(self):
		szName = self.WIDGET_ID + str(self.nWidgetCount)
		self.nWidgetCount += 1
		return szName

	def deleteAllWidgets(self):
		screen = self.getScreen()
		i = self.nWidgetCount - 1
		while (i >= 0):
			self.nWidgetCount = i
			screen.deleteWidget(self.getNextWidgetName())
			i -= 1

		self.nWidgetCount = 0

	# Will handle the input for this screen...
	def handleInput(self, inputClass):
		'Calls function mapped in EuropeScreenInputMap'

		if (inputClass.getNotifyCode() == NotifyCode.NOTIFY_CLICKED):

			if (inputClass.getButtonType() == WidgetTypes.WIDGET_GENERAL):

				if (inputClass.getData1() == self.BUY_UNIT_BUTTON_ID) :
					popupInfo = CyPopupInfo()
					popupInfo.setData1(1)
					popupInfo.setData3(TradeRouteTypes.TRADE_ROUTE_SPICE_ROUTE)
					popupInfo.setButtonPopupType(ButtonPopupTypes.BUTTONPOPUP_PURCHASE_EUROPE_UNIT)
					CyInterface().addPopup(popupInfo, gc.getGame().getActivePlayer(), true, false)

				elif (inputClass.getData1() == self.SAIL_TO_NEW_WORLD) :
					activePlayer = gc.getPlayer(gc.getGame().getActivePlayer())
					transport = activePlayer.getUnit(inputClass.getData2())
					if (not transport.isNone()) and transport.getUnitTravelState() != UnitTravelStates.UNIT_TRAVEL_STATE_FROM_SPICE_ROUTE:
						CyMessageControl().sendDoCommand(inputClass.getData2(), CommandTypes.COMMAND_SAIL_SPICE_ROUTE, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_SPICE_ROUTE, self.EUROPE_EAST, false)

				#elif (inputClass.getData1() == self.SAIL_TO_NEW_WORLD_WEST) :
				#	activePlayer = gc.getPlayer(gc.getGame().getActivePlayer())
				#	transport = activePlayer.getUnit(inputClass.getData2())
				#	if (not transport.isNone()) and transport.getUnitTravelState() != UnitTravelStates.UNIT_TRAVEL_STATE_FROM_SPICE_ROUTE:
				#		CyMessageControl().sendDoCommand(inputClass.getData2(), CommandTypes.COMMAND_SAIL_SPICE_ROUTE, UnitTravelStates.UNIT_TRAVEL_STATE_FROM_SPICE_ROUTE, self.EUROPE_WEST, false)

				elif (inputClass.getData1() == self.SELL_ALL) :
					player = gc.getPlayer(gc.getGame().getActivePlayer())
					transport = player.getUnit(inputClass.getData2())

					(unit, iter) = player.firstUnit()
					while (unit):
						if (unit.getUnitTravelState() == UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE and unit.isCargo() and unit.isGoods()):
							if (unit.getTransportUnit().getID() == transport.getID()):
								CyMessageControl().sendPlayerAction(player.getID(), PlayerActionTypes.PLAYER_ACTION_SELL_YIELD_UNIT, 0, unit.getYieldStored(), unit.getID())
						(unit, iter) = player.nextUnit(iter)

				elif (inputClass.getData1() == self.LOAD_ALL) :
					player = gc.getPlayer(gc.getGame().getActivePlayer())
					transport = player.getUnit(inputClass.getData2())
					for i in range(player.getNumEuropeUnits()):
						loopUnit = player.getEuropeUnit(i)
						if (not transport.isNone() and transport.getUnitTravelState() == UnitTravelStates.UNIT_TRAVEL_STATE_IN_SPICE_ROUTE and not transport.isFull()):
							CyMessageControl().sendPlayerAction(player.getID(), PlayerActionTypes.PLAYER_ACTION_LOAD_UNIT_FROM_EUROPE, loopUnit.getID(), inputClass.getData2(), -1)

		return 0

	def update(self, fDelta):
		if (CyInterface().isDirty(InterfaceDirtyBits.EuropeScreen_DIRTY_BIT)):
			CyInterface().setDirty(InterfaceDirtyBits.EuropeScreen_DIRTY_BIT, False)
			self.drawContents()
		#TKs Inventor
		if (gc.getGame().isIndustrialVictoryAll()):
			iVictoryYieldCount = gc.getPlayer(gc.getGame().getActivePlayer()).getVictoryYieldCount(gc.getDefineINT("INDUSTRIAL_VICTORY_SINGLE_YIELD"))
			if (self.TOTAL_CLOTH != iVictoryYieldCount):
				self.TOTAL_CLOTH = iVictoryYieldCount
				szText = localText.getText("TXT_KEY_VICTORY_SCREEN_DISCOVER_TEC_YIELD", (gc.getYieldInfo(gc.getDefineINT("INDUSTRIAL_VICTORY_SINGLE_YIELD")).getChar(), ))
				szText = localText.changeTextColor(localText.getText("TXT_KEY_EUROPE_INDUSTRIAL_HELP", (iVictoryYieldCount,)), gc.getInfoTypeForString("COLOR_FONT_CREAM")) + szText
				screen = self.getScreen()
				screen.setText("Industrial", "Background", u"<font=4>" + szText + u"</font>", CvUtil.FONT_RIGHT_JUSTIFY, (self.XResolution / 4) * 3 + (self.XResolution / 6), self.Y_TITLE, 0, FontTypes.GAME_FONT, WidgetTypes.WIDGET_GENERAL, -1, -1)
		#Tke

	def getWidgetHelp(self, argsList):
		iScreen, eWidgetType, iData1, iData2, bOption = argsList

		if eWidgetType == WidgetTypes.WIDGET_GENERAL:
			if iData1 == self.SAIL_TO_NEW_WORLD:
				#Tks Med
				player = gc.getPlayer(gc.getGame().getActivePlayer())
				if gc.getCivilizationInfo(player.getCivilizationType()).isWaterStart():
					return localText.getText("TXT_KEY_SAIL", ()) + " - " + localText.getObjectText("TXT_KEY_EUROPE_EAST", 0)
				else:
					return localText.getText("TXT_KEY_LEAVE", ())
			#if iData1 == self.SAIL_TO_NEW_WORLD_WEST:
			#	player = gc.getPlayer(gc.getGame().getActivePlayer())
			#	if gc.getCivilizationInfo(player.getCivilizationType()).isWaterStart():
			#		return localText.getText("TXT_KEY_SAIL", ()) + " - " + localText.getObjectText("TXT_KEY_EUROPE_WEST", 0)
			#	else:
			#		return localText.getText("TXT_KEY_LEAVE", ()) + " - " + localText.getObjectText("TXT_KEY_EUROPE_WEST", 0)
				#TKe
			elif iData1 == self.SELL_ALL:
				return localText.getText("TXT_KEY_SELL_ALL", ())
			elif iData1 == self.LOAD_ALL:
				return localText.getText("TXT_KEY_LOAD_ALL_EUROPE", ())
			elif iData1 == self.BUY_UNIT_BUTTON_ID:
				return localText.getText("TXT_KEY_PURCHASE_EUROPE", ())
			elif iData1 == self.TREASURY_ID:
				return localText.getText("TXT_KEY_ECON_GOLD_RESERVE", ())
			elif iData1 == self.HELP_CROSS_RATE:
				player = gc.getPlayer(gc.getGame().getActivePlayer())
				#Tks Med
				return localText.getText("TXT_KEY_YIELD_MULTI_RATE", (player.getMultiYieldRate(YieldTypes.YIELD_CROSSES), gc.getYieldInfo(YieldTypes.YIELD_CROSSES).getChar(), gc.getYieldInfo(YieldTypes.YIELD_BELLS).getChar(), gc.getYieldInfo(YieldTypes.YIELD_EDUCATION).getChar()))
				#Tke

		return u""

