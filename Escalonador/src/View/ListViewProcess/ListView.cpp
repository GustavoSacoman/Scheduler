#include "../include/Window.h"
#include <commctrl.h>
#include "../include/CreateObjectWindow.h"
#include "../include/ListView.h"


void CreateListView(Window* newWindow,HWND hwnd) {

	static HWND hListView = nullptr;
	
	hListView = CreateWindowEx(NULL,
		WC_LISTVIEW,
		L"view",
		WS_CHILD | WS_VISIBLE | LVS_REPORT,
		10, 10, 380, 250,
		newWindow->getHwnd(),
		(HMENU)1,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);
	
	CreateCollumn(hListView, L"PID",0);
	CreateCollumn(hListView, L"Priority",1);
	CreateCollumn(hListView, L"Rest_time", 2);
	CreateCollumn(hListView, L"Status", 3);


}



void CreateCollumn(HWND hListView, const std::wstring& nameColumn,int ColumnNumber) {
	
	wchar_t	subItemText[] = L"subitem";
	wchar_t itemText2[] = L"item2";

    LVCOLUMN lvColumn;
    lvColumn.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
    lvColumn.cx = 100;
    lvColumn.pszText = const_cast<LPWSTR>(nameColumn.c_str());
    ListView_InsertColumn(hListView, ColumnNumber, &lvColumn);

	ListView_InsertItem(hListView, &lvColumn, 0);
/*
* 
* LVITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = 0;
	lvItem.iSubItem = 0;
	lvItem.pszText = itemText;
	ListView_InsertItem(hListView, &lvItem,0);
	wchar_t subItemText[] = L"subitem";
	wchar_t itemText2[] = L"item2";
	lvItem.iItem = 1;
	lvItem.iSubItem = 0;
	lvItem.pszText = itemText2;
	ListView_InsertItem(hListView, &lvItem);
	LVITEM lvSubItem;
	lvSubItem.mask = LVIF_TEXT;
	lvSubItem.iItem = 0;             // Same row index
	lvSubItem.iSubItem = 1;          // Column 1
	lvSubItem.pszText = subItemText; // Text for column 1
	ListView_SetItem(hListView, &lvSubItem);


	wchar_t subItdfgdfemText[] = L"sudfgdgbitem";
	LVITEM lvasdads;
	lvSubItem.mask = LVIF_TEXT;
	lvSubItem.iItem = 0;             // Same row index
	lvSubItem.iSubItem = 0;          // Column 1
	lvSubItem.pszText = subItdfgdfemText; // Text for column 1
	ListView_SetItem(hListView, &lvasdads);


	lvItem.iItem = 1;
	lvItem.iSubItem = 0;
	lvItem.pszText = itemText2;
	ListView_InsertItem(hListView, &lvItem);*/


}