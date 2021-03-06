
// GProjectDemo2View.cpp : CGProjectDemo2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GProjectDemo2.h"
#endif

#include "GProjectDemo2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//int* p = new int;

CMapX m_ctrlMapX;


// CGProjectDemo2View

IMPLEMENT_DYNCREATE(CGProjectDemo2View, CView)

BEGIN_MESSAGE_MAP(CGProjectDemo2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGProjectDemo2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_OPEN, &CGProjectDemo2View::OnFileOpen)
	ON_COMMAND(ID_BUTTON32791, &CGProjectDemo2View::OnButton32791)
	ON_COMMAND(ID_BUTTON32792, &CGProjectDemo2View::OnButton32792)
	ON_COMMAND(ID_BUTTON32793, &CGProjectDemo2View::OnButton32793)
	ON_COMMAND(ID_BUTTON32794, &CGProjectDemo2View::OnButton32794)
	ON_COMMAND(ID_BUTTON32795, &CGProjectDemo2View::OnButton32795)
	ON_COMMAND(ID_32774, &CGProjectDemo2View::InitDataBase)
	ON_COMMAND(ID_TESTDBCONNECTION, &CGProjectDemo2View::OnTestdbconnection)
	ON_COMMAND(ID_BINDDATA, &CGProjectDemo2View::OnBinddata)
	ON_COMMAND(ID_GRIDMAKER, &CGProjectDemo2View::OnGridmaker)
	ON_COMMAND(ID_INTERSECTION, &CGProjectDemo2View::OnIntersection)
	ON_COMMAND(ID_RECORDBUILDING, &CGProjectDemo2View::OnRecordbuilding)
	//ON_COMMAND(ID_RECORDGRID, &CGProjectDemo2View::OnRecordgrid)
	ON_COMMAND(ID_MODIFY, &CGProjectDemo2View::OnModify)
	ON_COMMAND(ID_PUTXY, &CGProjectDemo2View::OnPutxy)
	ON_COMMAND(ID_RECORDBS, &CGProjectDemo2View::OnOpenbsxls)
	ON_COMMAND(ID_RECORDRTDATA, &CGProjectDemo2View::OnRecordrtdata)
	ON_COMMAND(ID_CALCULATE, &CGProjectDemo2View::OnCalculate)
	ON_COMMAND(ID_GRIDMIF, &CGProjectDemo2View::OnGridmif)
	ON_COMMAND(ID_CHANGE, &CGProjectDemo2View::OnChange)
END_MESSAGE_MAP()

// CGProjectDemo2View 构造/析构

CGProjectDemo2View::CGProjectDemo2View()
{
	//配置数据库，创建连接
	DBConnPool::Instanse()->SetDBInfo("127.0.0.1","sa","123456","MapData",10,20);
	//清空现有的数据
	//DBHelper::deleteAllTable();
}

CGProjectDemo2View::~CGProjectDemo2View()
{
}

BOOL CGProjectDemo2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	return CView::PreCreateWindow(cs);
}

// CGProjectDemo2View 绘制

void CGProjectDemo2View::OnDraw(CDC* /*pDC*/)
{
	CGProjectDemo2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}



void CGProjectDemo2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGProjectDemo2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGProjectDemo2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGProjectDemo2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CGProjectDemo2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGProjectDemo2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGProjectDemo2View 诊断

#ifdef _DEBUG
void CGProjectDemo2View::AssertValid() const
{
	CView::AssertValid();
}

void CGProjectDemo2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGProjectDemo2Doc* CGProjectDemo2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGProjectDemo2Doc)));
	return (CGProjectDemo2Doc*)m_pDocument;
}
#endif //_DEBUG




int CGProjectDemo2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CString strLic = "uQnZi2sFw22L0-MRa8pYX-5E6P0001-6N1M5491-2C935277-58254-34356-52488";
	BSTR bstrLic = strLic.AllocSysString();
	BOOL bSucceed = m_ctrlMapX.Create(NULL, WS_VISIBLE, CRect(0,0,100,100),this,IDC_MAP, NULL, FALSE, bstrLic);
	if(!bSucceed) {
		return -1;
	}
	::SysFreeString(bstrLic);
	//if(!m_ctrlMapX.Create(NULL,WS_VISIBLE,CRect(0,0,100,100),this,IDC_MAP))
	//	return -1;
	m_ctrlMapX.GetLayers().RemoveAll();
	m_ctrlMapX.SetTitleText(_T(""));
	m_ctrlMapX.SetMousewheelSupport(miFullMousewheelSupport);
	/*m_ctrlMapX.SetCenterX(116.36652);
	m_ctrlMapX.SetCenterY(39.88292);
	m_ctrlMapX.SetZoom(0.1);*/
	return 0;
}


void CGProjectDemo2View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	if(cx!=0&&cy!=0)
	{
		m_ctrlMapX.MoveWindow(0,0,cx,cy,TRUE);
	}
	// TODO: 在此处添加消息处理程序代码
}

void CGProjectDemo2View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	
	CString OpenFilter = _T("地图文件(*.tab)|*.tab;*.TAB|所有文件(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		try {
			CString FileName = FileDlgOpen.GetPathName();
			CString FilePartName = FileDlgOpen.GetFileTitle();
			m_ctrlMapX.GetLayers().Add(FileName);
			//将layer绑定到dataset中
			VARIANT vtLayer;
			vtLayer.vt=VT_DISPATCH;
			vtLayer.pdispVal=m_ctrlMapX.GetLayers().Item(m_ctrlMapX.GetLayers().GetCount()).m_lpDispatch;
			m_ctrlMapX.GetDatasets().Add(miDataSetLayer,vtLayer,FilePartName);
			double X,Y;
			m_ctrlMapX.SetBounds(m_ctrlMapX.GetLayers().GetBounds());
			/*m_ctrlMapX.SetCenterX(116.36652);
			m_ctrlMapX.SetCenterY(39.88292);
			m_ctrlMapX.SetZoom(0.1);*/

		//尝试是否已经包含了建筑物数据   结论：可以从mapx中直接取出数据！！  不用手动的提取.mif文件
		
			CMapXFeatures m_Features = m_ctrlMapX.GetLayers().Item(m_ctrlMapX.GetLayers().GetCount()).AllFeatures();
			
			for(int m = 1;m<=m_Features.GetCount();m++) {
				CMapXParts  m_Feature = m_Features.Item(m).GetParts();
				CMapXPoints m_Points = m_Feature.Item(1);
				int count = m_Points.GetCount();
				double x1 = m_Points.Item(1).GetX();
				double y1 = m_Points.Item(1).GetY();
				double x2 = m_Points.Item(m_Points.GetCount()).GetX();
				double y2 = m_Points.Item(m_Points.GetCount()).GetY();
				int freaturesCount = m_Features.GetCount();
			}
			
			//X = m_ctrlMapX.GetLayers().Item(1).AllFeatures().Item(1).GetCenterX();
		} catch(COleDispatchException* e) {
			e->ReportError();
			e->Delete();
		} catch(COleException* e) {
			e->ReportError();
			e->Delete();
		}
		
		
		                                                                                                                                  
	}
}


void CGProjectDemo2View::OnButton32791()
{
	// TODO: 在此添加命令处理程序代码
	m_ctrlMapX.SetCurrentTool(miZoomInTool);
}


void CGProjectDemo2View::OnButton32792()
{
	// TODO: 在此添加命令处理程序代码
	m_ctrlMapX.SetCurrentTool(miZoomOutTool);
}


void CGProjectDemo2View::OnButton32793()
{
	// TODO: 在此添加命令处理程序代码
	m_ctrlMapX.SetCurrentTool(miPanTool);
}


void CGProjectDemo2View::OnButton32794()
{
	// TODO: 在此添加命令处理程序代码
	m_ctrlMapX.SetCurrentTool(miArrowTool);
}


void CGProjectDemo2View::OnButton32795()
{
	// TODO: 在此添加命令处理程序代码
	m_ctrlMapX.GetLayers().LayersDlg();
}

//此函数想用来配置数据库的，应该调用一个对话框出来，可能之后不放在VIEW下，注意点。
void CGProjectDemo2View::InitDataBase()
{
	// TODO: 在此添加命令处理程序代码
	//现在采用默认连接，不提供外部的输入，之后需要改成可配置的
	

}


void CGProjectDemo2View::OnTestdbconnection()
{
	// TODO: 在此添加命令处理程序代码
	//按照传入的配置信息，进行数据库的连接，并返回结果 
	DBConnect* dbconnection;
	try {
		//返回数据
		dbconnection = DBConnPool::Instanse()->GetAConnection();
		DBConnPool::Instanse()->RestoreAConnection(dbconnection);
		MessageBox(_T("数据库连接成功"),_T("数据库连接测试"),MB_OKCANCEL);
	} catch(_com_error e) {
		DBConnPool::Instanse()->RestoreAConnection(dbconnection);
		cout<<e.Description()<<endl;
		MessageBox(_T("数据库连接失败"),_T("数据库连接测试"),MB_OKCANCEL);
	}
	//此处采用默认连接数据库的配置
	/*
	_ConnectionPtr connection;
	_RecordsetPtr recordSet;
	HRESULT hr = connection.CreateInstance(__uuidof(Connection));
	recordSet.CreateInstance(__uuidof(Recordset));
	string queryString = "select * from CUT;";
	_bstr_t sqlString  = queryString.c_str();
	connection->Open("Driver=SQL Server;Server=127.0.1;DATABASE=MapData","sa","123456",adModeUnknown) ;
	if (FAILED(hr))
		return;
	recordSet->Open(sqlString,connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

	MessageBox(_T("数据库连接成功"),_T("数据库连接测试"),MB_OKCANCEL);
	if(recordSet->State) {
		recordSet->Close();
	}
	if(connection->State) {
		connection->Close();
	}
	*/
	//制作主题地图
	/*
	CMapXTheme thm;
	thm=m_ctrlMapX.GetDatasets().Item(1).GetThemes().Add(miThemeRanged,_T("x"),_T("value"));
	*/


	/*
	CMapXFields field;
	field.CreateDispatch(field.GetClsid());
	field.AddNumericField(_T("x"),10,0);
	field.AddNumericField(_T("y"),10,0);
	CString name[2]={_T("x"),_T("y")};
	
	VARIANT vFlds;
	vFlds.vt = VT_DISPATCH;
	vFlds.pdispVal = field.m_lpDispatch;
	*/
	
	//thm=m_ctrlMapX.GetDatasets().Item(1).GetThemes().Add(miThemeRanged,_T("y"),_T("value2"));
	
	/*
	CMapXFeatures features;
	CMapXFeature feature;
	feature.set
	*/
	//尝试实现数据绑定  用途：用来将场强数据绑定到各个网格中
	//现在尝试实现的是  将自己手动生成的数据绑定到建筑物中
	/*
	CMapXDatasets m_Datasets = m_ctrlMapX.GetDatasets();
	CMapXFields m_Fields;
	m_Fields.Add(2,_T("BuildingValue"),miAggregationAuto);
	DataBase database;
	string sqlString = "select * from BuildingBindTest;";
	*/
	}




void CGProjectDemo2View::OnBinddata()
{
	//进行文本绑定~
	// TODO: 在此添加命令处理程序代码
	/*
	HGLOBAL hGlobalData = NULL;
	char* psz = NULL;
	CString OpenFilter = _T("场强文件(*.txt)|*.txt;*.TXT|所有文件(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDCANCEL == FileDlgOpen.DoModal()) {
		return;
	}
	CFile fileData(FileDlgOpen.GetPathName(),CFile::modeRead);
	CString strBuffer;
	fileData.Read(strBuffer.GetBuffer(fileData.GetLength()+1),fileData.GetLength());
	strBuffer.ReleaseBuffer(fileData.GetLength()+1);
	fileData.Close();
	hGlobalData=GlobalAlloc(GMEM_MOVEABLE,strBuffer.GetLength()+1);
	psz = (char*) GlobalLock(hGlobalData);

	char* pbuf=NULL;
	int iNum=0;
	iNum=strBuffer.GetLength();
	pbuf=new char[iNum+1];
	memset(pbuf,0,iNum+1);
	memcpy(pbuf,strBuffer.GetBuffer(iNum),iNum);
	const char* p=pbuf;
	strcpy(psz,p);
	//strcpy(psz,strBuffer.GetBuffer(sizeof(strBuffer)));
	GlobalUnlock(hGlobalData);

	short type;
	VARIANT sourceData;
	VARIANT name;
	VARIANT secondaryGeoField;
	VARIANT bindLayerName;
	VARIANT fields;
	CString strname("TestData");
	secondaryGeoField.vt=VT_ERROR;
	secondaryGeoField.scode=DISP_E_PARAMNOTFOUND;

	//bindLayerName.vt = VT_BSTR;
	//bindLayerName.bstrVal=_T("cut");
	bindLayerName.vt = VT_ERROR;
	bindLayerName.scode=DISP_E_PARAMNOTFOUND;

	fields.vt=VT_ERROR;
	fields.scode=DISP_E_PARAMNOTFOUND;

	
	CMapXFields flds;
	flds.CreateDispatch(flds.GetClsid());
	flds.Add(_T("x"),_T("x"),5);
	flds.Add(_T("y"),_T("y"),5);
	                
	name.vt=VT_BSTR;
	name.bstrVal=strname.AllocSysString();

	type=miDataSetGlobalHandle;
	sourceData.vt=VT_I4;
	sourceData.iVal=(long) hGlobalData;

	try {
		CMapXDataset ds = m_ctrlMapX.GetDatasets().Add(type,sourceData,name,COleVariant(1L),secondaryGeoField,
			bindLayerName,fields,COptionalVariant());
		int count = ds.GetRowCount();
		//CMapXFields m_Fields = ds.GetFields();
		//double value = m_Fields.Item(1).GetWidth();
	} catch(COleDispatchException* e) {
		e->ReportError();
		e->Delete();
	}
	*/

	//ADO绑定
	/*
	try {
		short type=miDataSetODBC;
		VARIANT sourceData;

		VARIANT name;
		CString strname("BindData");
		name.vt=VT_BSTR;
		name.bstrVal=strname.AllocSysString();

		VARIANT firstGeoField;
		VARIANT secondaryGeoField;
		VARIANT bindLayerName;
		VARIANT fields;

		CMapXDataset ds = m_ctrlMapX.GetDatasets().Add(type,sourceData,name,COleVariant(1L),secondaryGeoField,
			bindLayerName,fields,COptionalVariant());
	} catch(COleDispatchException* e) {
		e->ReportError();
		e->Delete();
	}
	*/
	//数据绑定
	// layer.add 绑定   ODBC
	/*
	VARIANT sourceData,name,geoField,secondGeoField,bindLayerName,fields,dynamicState;
	short type = miDataSetODBC;

	name.vt = VT_BSTR;
	name.bstrVal=_T("BindData");

	CMapXODBCQueryInfo queryInfo; //此处需要对modbcdataset.dll(在mapx的安装目录下）进行注册   regsvr32  modbcdataset.dll(在该dll所在目录下)
	queryInfo.SetConnectString(_T("ODBC;user=sa,pwd=123456;DLG=2"));
	//queryInfo.SetDataSource(_T("SQL SERVER")); //DBMS:Microsoft SQL Server Database:MapData 
	queryInfo.SetSqlQuery(_T("select * from Grid;"));
	sourceData.pdispVal=queryInfo.m_lpDispatch; //

	geoField.vt=VT_BSTR;
	geoField.bstrVal=_T("GLongitude");
	secondGeoField.vt=VT_BSTR;
	secondGeoField.bstrVal=_T("GLatitude");
	
	
	CMapXFields flds;
	flds.CreateDispatch(flds.GetClsid());
	flds.Add(_T("GLongitude"),_T("GLongitude"),miAggregationAuto);
	flds.Add(_T("GLatitude"),_T("GLatitude"),miAggregationAuto);
	flds.Add(_T("GRealSNR"),_T("BindData"),miAggregationAuto);
	fields.pdispVal=flds.m_lpDispatch;
	/*
	/*
	flds.AddIntegerField(_T("GId"),FALSE);
	flds.AddNumericField(_T("GLongitude"),9,6);
	flds.AddNumericField(_T("GLatitude"),9,6);
	flds.AddNumericField(_T("GRealSNR"),6,3); //GRealSNR中存放校正过后的，每个网格中对应的信噪比
	fields.pdispVal=flds.m_lpDispatch;
	*/

	//包含全部的字段 
	//fields.vt = VT_ERROR;
	//fields.scode = DISP_E_PARAMNOTFOUND;

	//此处仍然存在的问题是，如何将对应的数据绑定到对应的图元上？？？？？？

	/*
	bindLayerName.vt=VT_BSTR;
	bindLayerName.bstrVal=_T("gridMaker");

	dynamicState.vt = VT_BOOL;
	dynamicState.boolVal=false;
	//OBJECT.Add( Type, SourceData, [Name], [Geofield], [SecondaryGeofield], [BindLayer], [Fields], [Dynamic] )
	m_ctrlMapX.GetDatasets().Add(type,sourceData,name,geoField,secondGeoField,bindLayerName,fields,dynamicState);
	*/
	/*
	CMapXTheme thm;
	thm=m_ctrlMapX.GetDatasets().Item(_T("gridMaker")).GetThemes().Add(miThemeRanged,_T("x"),_T("value"));
	*/
    
	


	//LayerInfo 
	/*
	CMapXLayerInfo m_mapxLayerInfo;
	if(!m_mapxLayerInfo.CreateDispatch(m_mapxLayerInfo.GetClsid())) {
		TRACE0("Failed To Create LayerInfo");
		return;
	}
	try {
	
		m_mapxLayerInfo.SetType(miLayerInfoTypeServer);	

		VARIANT sVt;
		sVt.vt = VT_BSTR;
		CString strName;
		strName = "LayerName";
		sVt.bstrVal=strName.AllocSysString();
		//添加NAME参数
		m_mapxLayerInfo.AddParameter(_T("Name"),sVt);
		CString strConnect;
		//strConnect = "DRIVER={SQL SERVER};SERVER=LITIANJIE-PC;UID=sa;PWD=123456;Database=MapData";
		strConnect = "DRIVER={SQL SERVER};SERVER=LITIANJIE-PC;UID=sa;PWD=123456;Database=MapData";
		sVt.bstrVal = strConnect.AllocSysString();
		m_mapxLayerInfo.AddParameter(_T("ConnectString"),sVt);
		CString strQuery;
		strQuery = "select * from BuildingBindTest;";
		sVt.bstrVal=strQuery.AllocSysString();
		m_mapxLayerInfo.AddParameter(_T("query"),sVt);
		CString strToolKit;
		strToolKit="ODBC";
		sVt.bstrVal=strToolKit.AllocSysString();
		m_mapxLayerInfo.AddParameter(_T("toolkit"),sVt);
		COleVariant cache(_T("ON")),mbrsearch(_T("ON"));
		//cache="OFF";
		//mbrsearch="ON";
		m_mapxLayerInfo.AddParameter(_T("cache"),cache);
		m_mapxLayerInfo.AddParameter(_T("mbrsearch"),mbrsearch);
		
		int k = 1;
		sVt.vt = VT_I4;
		sVt.iVal = k;
		//m_mapxLayerInfo.AddParameter(_T("AutoCreateDataset"),sVt);
		
		m_ctrlMapX.GetLayers().Add(m_mapxLayerInfo);
		m_ctrlMapX.Refresh();
	} catch(COleException *e) {
		e->ReportError();
		e->Delete();
	} 
	*/
/*
	DataBase db;
	string sqlString = "select * from Grid;";
	
	_RecordsetPtr  rs = db.getObjectInfoRecordset(sqlString);
	//填写绑定的数据来源
	m_ctrlMapX.GetDatasets().Add(miDataSetADO,rs->,_T("BindData"),0);
	*/
	

	//尝试不使用数据绑定，直接往features中添加fields
	//失败，看到的都是采用添加新的layinfo来创建一个新图层；而实际中需要的是在gridmaker图层中
	//给grid添加字段，这样将gridmaker的场强数据取出来后可以直接画专题图！！！！
	
}


void CGProjectDemo2View::OnGridmaker()
{
	MakeGrid::makeGrid();
	MessageBox(_T("恭喜您，网格生成成功"),_T("录入信息"),MB_OK);
}

//
//void CGProjectDemo2View::createGridMapPoints(double minLongitude,double maxLongtitude,double minLatitude,double maxLatitude) {
//	CMapXLayer lyr = m_ctrlMapX.GetLayers().CreateLayer(_T("gridMaker"),_T("E:\\Franklin\\program\\mapinfo\\mapx\\Maps\\Test_Map\\gridMaker.tab"));
//	
//	//为了避免有的建筑物不在网格中，将经纬度分别给0.001的余地
//	double redundency=0.001;
//	minLongitude-=redundency;
//	minLatitude-=redundency;
//	maxLongtitude+=redundency;
//	maxLatitude+=redundency;
//	//经度增大，维度减小
//	CGProjectDemo2View cView;
//	CMapXPoints points;
//
//	lyr.AddFeature(cView.createGridPoints(minLongitude,maxLatitude));
//	lyr.Refresh();
//	long count = lyr.AllFeatures().GetCount();
//}
//
//CMapXFeature  CGProjectDemo2View::createGridPoints(double longitude,double latitude) {
//	double x1=longitude;
//	double y1 = latitude;
//	double x2 = longitude+longilength;
//	double y2 = latitude-latilength;
//	CMapXFeatureFactory featureFactory = m_ctrlMapX.GetFeatureFactory();
//	CMapXPoints points;
//	points.CreateDispatch(points.GetClsid());
//	CMapXPoint point;
//	point.CreateDispatch(point.GetClsid());
//	point.Set(x1,y1);
//	points.Add(point);
//	point.Set(x2,y1);
//	points.Add(point);
//	point.Set(x2,y2);
//	points.Add(point);
//	point.Set(x1,y2);
//	points.Add(point);
//	
//	VARIANT variantPoints;
//	variantPoints.vt=VT_DISPATCH;
//	variantPoints.pdispVal=points.m_lpDispatch;
//	variantPoints.pdispVal->AddRef();
//	
//	CMapXStyle sty;
//	sty.CreateDispatch(sty.GetClsid());
//	sty.SetRegionBorderWidth(1);
//	sty.SetRegionBorderColor(miColorBlack);
//	sty.SetRegionPattern(miPatternNoFill);
//	sty.SetRegionTransparent(1);
//	VARIANT variantSty;
//	variantSty.vt=VT_DISPATCH;
//	variantSty.pdispVal=sty.m_lpDispatch;
//	variantSty.pdispVal->AddRef();
//	CMapXFeature featureRegion=featureFactory.CreateRegion(variantPoints,variantSty);
//	return featureRegion;
//}

void CGProjectDemo2View::OnIntersection()
{
	RecordGridBuildingIntersectionTool::recordGridBuildingIntersectionTool();
	//基站和网格的关系是得按照SNR计算得出
	//RecordAreaGridIntersectionTool::recordAreaGridIntersectionTool();
	//建筑物和Area的关系不需要计算出来使用

	MessageBox(_T("恭喜您，相交信息已经录入成功"),_T("录入信息"),MB_OK);
}


void CGProjectDemo2View::OnRecordbuilding()
{
	// TODO: 在此添加命令处理程序代码
	/*
	//暂时先采用读取.mif，后期可以尝试使用mapx读取该图层，取出数据放入到数据库中
	CString pathName;
	CString fileName;

	TCHAR szFilters[]= _T("MIF Files (*.mif)|*.mif|All Files (*.*)|*.*||");

	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg(TRUE, _T("mif"), _T("*.mif"),
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters);
	if(fileDlg.DoModal() == IDOK)
	{
		pathName = fileDlg.GetPathName();

		// Implement opening and reading file in here.

		//Change the window's title to the opened file's title.
		fileName = fileDlg.GetFileTitle();

		RecordBuildingPointTool RBP;
		RBP.FilePosition=pathName;
		if(RBP.RecordBuildingLayerInfoToDB()==true)
			::MessageBox(NULL,_T("恭喜您，录入成功！"),_T("成功"),MB_OK);
	}
	*/

	RecordBuildingPointTool RBP;
	if(RBP.RecordBuildingLayerInfoToDB()==true)
		::MessageBox(NULL,_T("恭喜您，建筑物信息录入成功！"),_T("成功"),MB_OK);
}


void CGProjectDemo2View::OnRecordgrid()
{/*
	if(RecordGridInfoTool::recordGridInfoToDB()==true) {
		::MessageBox(NULL,_T("恭喜您，网格信息录入成功!"),_T("录入信息提示"),MB_OK);
	}*/
}


void CGProjectDemo2View::OnOpenbsxls()
{
	//int* p = new int;
	// TODO: 在此添加命令处理程序代码
	CString OpenFilter = _T("基站文件(*.csv)|*.csv;*.CSV|所有文件(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		CString FileName = FileDlgOpen.GetPathName();
		CString FilePartName = FileDlgOpen.GetFileTitle();
		//清除掉原有的数据库信息
		bool flag = RecordAreaInfoTool::insertAreaInfo(FileName);
		if(flag) {
			MessageBox(_T("恭喜您，基站数据录入成功!"),_T("通知"),MB_OK);
		} else {
			MessageBox(_T("很抱歉，基站数据录入有问题!"),_T("通知"),MB_OK);
		}
	}
}


void CGProjectDemo2View::OnModify()
{
	// TODO: 在此添加命令处理程序代码
/*
	double raw[5]={1.2,1.3,1.5,1.4,1.7};
	double rawPart[2]={1.2,1.4};
	double lt[2]={1.3,1.6};
	double final[5];
	vector<double> finalVector=ModifyLTTool::getArrayModifyData(raw,ARRAYSIZE(raw),rawPart,ARRAYSIZE(rawPart),lt,ARRAYSIZE(lt));
	cout<<"haha"<<endl;
	*/
//	ModifyLTTool::modiyData();
	MessageBox(_T("数据校正模块取消！"),_T("通知"),MB_OK);
}


void CGProjectDemo2View::OnPutxy()
{
	// TODO: 在此添加命令处理程序代码
	PutXY::ChangeToXY();
	MessageBox(_T("恭喜您，XY放置已经完成!"),_T("通知"),MB_OK);
}




void CGProjectDemo2View::OnRecordrtdata()
{
	// TODO: 在此添加命令处理程序代码
	CString OpenFilter = _T("路测文件(*.xls,*.xlsx)|*.xls;*.XLS;*.xlsx;*.XLSX|所有文件(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		CString FileName = FileDlgOpen.GetPathName();
		CString FilePartName = FileDlgOpen.GetFileTitle();
		//清除掉原有的数据库信息
		bool flag = RecordRTData::recordRTData(FileName);
		if(flag) {
			MessageBox(_T("恭喜您，路测数据录入成功!"),_T("通知"),MB_OK);
		} else {
			MessageBox(_T("很抱歉，路测数据录入有问题!"),_T("通知"),MB_OK);
		}
	}
}


void CGProjectDemo2View::OnCalculate()
{
	// TODO: 在此添加命令处理程序代码
	//调用张喆的模块，进行场强的计算
	GetStrongestStrength::getStrongestStrength();
	MessageBox(_T("恭喜您，计算数据成功!"),_T("通知"),MB_OK);
}


void CGProjectDemo2View::OnGridmif()
{
	// TODO: 在此添加命令处理程序代码
	CString OpenFilter = _T("网格文件(*.mif)|*.mif;*.MIF|所有文件(*.*)|*.*||");
	CFileDialog FileDlgOpen(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		CString FileName = FileDlgOpen.GetPathName();
		string fileNameString = FileName.GetBuffer(0);
		fileNameString.append(".mif"); 
		//将场强值和颜色进行对应的改变
		SetGridColorTool::SetColor();
		MessageBox(_T("恭喜您，颜色信息已经转换成功!"),_T("通知"),MB_OK);
		//从数据库中取出网格的颜色信息进行展示
		MakeGridFileTool::makeGridFile(fileNameString);
		MessageBox(_T("恭喜您，已经生成网格MIF文件!"),_T("通知"),MB_OK);
	}
}


void CGProjectDemo2View::OnChange()
{
	// TODO: 在此添加命令处理程序代码
	clock_t startTime = GetTickCount();
	GridBSDistanceCal::updateDistance();
	clock_t endTime = GetTickCount();
	DWORD lastTime = endTime-startTime;
	cout<<lastTime;
	MessageBox(_T("计算完成"),_T("通知"),MB_OK);

}
