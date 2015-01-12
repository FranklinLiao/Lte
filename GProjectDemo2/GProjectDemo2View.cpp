
// GProjectDemo2View.cpp : CGProjectDemo2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CGProjectDemo2View ����/����

CGProjectDemo2View::CGProjectDemo2View()
{
	//�������ݿ⣬��������
	DBConnPool::Instanse()->SetDBInfo("127.0.0.1","sa","123456","MapData",10,20);
	//������е�����
	//DBHelper::deleteAllTable();
}

CGProjectDemo2View::~CGProjectDemo2View()
{
}

BOOL CGProjectDemo2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	return CView::PreCreateWindow(cs);
}

// CGProjectDemo2View ����

void CGProjectDemo2View::OnDraw(CDC* /*pDC*/)
{
	CGProjectDemo2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ�����������ӻ��ƴ���
}



void CGProjectDemo2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGProjectDemo2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGProjectDemo2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ���Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGProjectDemo2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ���Ӵ�ӡ����е���������
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


// CGProjectDemo2View ���

#ifdef _DEBUG
void CGProjectDemo2View::AssertValid() const
{
	CView::AssertValid();
}

void CGProjectDemo2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGProjectDemo2Doc* CGProjectDemo2View::GetDocument() const // �ǵ��԰汾��������
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
	// TODO: �ڴ˴�������Ϣ�����������
}

void CGProjectDemo2View::OnFileOpen()
{
	// TODO: �ڴ�����������������
	
	CString OpenFilter = _T("��ͼ�ļ�(*.tab)|*.tab;*.TAB|�����ļ�(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		try {
			CString FileName = FileDlgOpen.GetPathName();
			CString FilePartName = FileDlgOpen.GetFileTitle();
			m_ctrlMapX.GetLayers().Add(FileName);
			//��layer�󶨵�dataset��
			VARIANT vtLayer;
			vtLayer.vt=VT_DISPATCH;
			vtLayer.pdispVal=m_ctrlMapX.GetLayers().Item(m_ctrlMapX.GetLayers().GetCount()).m_lpDispatch;
			m_ctrlMapX.GetDatasets().Add(miDataSetLayer,vtLayer,FilePartName);
			double X,Y;
			m_ctrlMapX.SetBounds(m_ctrlMapX.GetLayers().GetBounds());
			/*m_ctrlMapX.SetCenterX(116.36652);
			m_ctrlMapX.SetCenterY(39.88292);
			m_ctrlMapX.SetZoom(0.1);*/

		//�����Ƿ��Ѿ������˽���������   ���ۣ����Դ�mapx��ֱ��ȡ�����ݣ���  �����ֶ�����ȡ.mif�ļ�
		
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
	// TODO: �ڴ�����������������
	m_ctrlMapX.SetCurrentTool(miZoomInTool);
}


void CGProjectDemo2View::OnButton32792()
{
	// TODO: �ڴ�����������������
	m_ctrlMapX.SetCurrentTool(miZoomOutTool);
}


void CGProjectDemo2View::OnButton32793()
{
	// TODO: �ڴ�����������������
	m_ctrlMapX.SetCurrentTool(miPanTool);
}


void CGProjectDemo2View::OnButton32794()
{
	// TODO: �ڴ�����������������
	m_ctrlMapX.SetCurrentTool(miArrowTool);
}


void CGProjectDemo2View::OnButton32795()
{
	// TODO: �ڴ�����������������
	m_ctrlMapX.GetLayers().LayersDlg();
}

//�˺����������������ݿ�ģ�Ӧ�õ���һ���Ի������������֮�󲻷���VIEW�£�ע��㡣
void CGProjectDemo2View::InitDataBase()
{
	// TODO: �ڴ�����������������
	//���ڲ���Ĭ�����ӣ����ṩ�ⲿ�����룬֮����Ҫ�ĳɿ����õ�
	

}


void CGProjectDemo2View::OnTestdbconnection()
{
	// TODO: �ڴ�����������������
	//���մ����������Ϣ���������ݿ�����ӣ������ؽ�� 
	DBConnect* dbconnection;
	try {
		//��������
		dbconnection = DBConnPool::Instanse()->GetAConnection();
		DBConnPool::Instanse()->RestoreAConnection(dbconnection);
		MessageBox(_T("���ݿ����ӳɹ�"),_T("���ݿ����Ӳ���"),MB_OKCANCEL);
	} catch(_com_error e) {
		DBConnPool::Instanse()->RestoreAConnection(dbconnection);
		cout<<e.Description()<<endl;
		MessageBox(_T("���ݿ�����ʧ��"),_T("���ݿ����Ӳ���"),MB_OKCANCEL);
	}
	//�˴�����Ĭ���������ݿ������
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

	MessageBox(_T("���ݿ����ӳɹ�"),_T("���ݿ����Ӳ���"),MB_OKCANCEL);
	if(recordSet->State) {
		recordSet->Close();
	}
	if(connection->State) {
		connection->Close();
	}
	*/
	//���������ͼ
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
	//����ʵ�����ݰ�  ��;����������ǿ���ݰ󶨵�����������
	//���ڳ���ʵ�ֵ���  ���Լ��ֶ����ɵ����ݰ󶨵���������
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
	//�����ı���~
	// TODO: �ڴ�����������������
	/*
	HGLOBAL hGlobalData = NULL;
	char* psz = NULL;
	CString OpenFilter = _T("��ǿ�ļ�(*.txt)|*.txt;*.TXT|�����ļ�(*.*)|*.*||");
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

	//ADO��
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
	//���ݰ�
	// layer.add ��   ODBC
	/*
	VARIANT sourceData,name,geoField,secondGeoField,bindLayerName,fields,dynamicState;
	short type = miDataSetODBC;

	name.vt = VT_BSTR;
	name.bstrVal=_T("BindData");

	CMapXODBCQueryInfo queryInfo; //�˴���Ҫ��modbcdataset.dll(��mapx�İ�װĿ¼�£�����ע��   regsvr32  modbcdataset.dll(�ڸ�dll����Ŀ¼��)
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
	flds.AddNumericField(_T("GRealSNR"),6,3); //GRealSNR�д��У������ģ�ÿ�������ж�Ӧ�������
	fields.pdispVal=flds.m_lpDispatch;
	*/

	//����ȫ�����ֶ� 
	//fields.vt = VT_ERROR;
	//fields.scode = DISP_E_PARAMNOTFOUND;

	//�˴���Ȼ���ڵ������ǣ���ν���Ӧ�����ݰ󶨵���Ӧ��ͼԪ�ϣ�����������

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
		//����NAME����
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
	//��д�󶨵�������Դ
	m_ctrlMapX.GetDatasets().Add(miDataSetADO,rs->,_T("BindData"),0);
	*/
	

	//���Բ�ʹ�����ݰ󶨣�ֱ����features������fields
	//ʧ�ܣ������Ķ��ǲ��������µ�layinfo������һ����ͼ�㣻��ʵ������Ҫ������gridmakerͼ����
	//��grid�����ֶΣ�������gridmaker�ĳ�ǿ����ȡ���������ֱ�ӻ�ר��ͼ��������
	
}


void CGProjectDemo2View::OnGridmaker()
{
	MakeGrid::makeGrid();
	MessageBox(_T("��ϲ�����������ɳɹ�"),_T("¼����Ϣ"),MB_OK);
}

//
//void CGProjectDemo2View::createGridMapPoints(double minLongitude,double maxLongtitude,double minLatitude,double maxLatitude) {
//	CMapXLayer lyr = m_ctrlMapX.GetLayers().CreateLayer(_T("gridMaker"),_T("E:\\Franklin\\program\\mapinfo\\mapx\\Maps\\Test_Map\\gridMaker.tab"));
//	
//	//Ϊ�˱����еĽ����ﲻ�������У�����γ�ȷֱ��0.001�����
//	double redundency=0.001;
//	minLongitude-=redundency;
//	minLatitude-=redundency;
//	maxLongtitude+=redundency;
//	maxLatitude+=redundency;
//	//��������ά�ȼ�С
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
	//��վ������Ĺ�ϵ�ǵð���SNR����ó�
	//RecordAreaGridIntersectionTool::recordAreaGridIntersectionTool();
	//�������Area�Ĺ�ϵ����Ҫ�������ʹ��

	MessageBox(_T("��ϲ�����ཻ��Ϣ�Ѿ�¼��ɹ�"),_T("¼����Ϣ"),MB_OK);
}


void CGProjectDemo2View::OnRecordbuilding()
{
	// TODO: �ڴ�����������������
	/*
	//��ʱ�Ȳ��ö�ȡ.mif�����ڿ��Գ���ʹ��mapx��ȡ��ͼ�㣬ȡ�����ݷ��뵽���ݿ���
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
			::MessageBox(NULL,_T("��ϲ����¼��ɹ���"),_T("�ɹ�"),MB_OK);
	}
	*/

	RecordBuildingPointTool RBP;
	if(RBP.RecordBuildingLayerInfoToDB()==true)
		::MessageBox(NULL,_T("��ϲ������������Ϣ¼��ɹ���"),_T("�ɹ�"),MB_OK);
}


void CGProjectDemo2View::OnRecordgrid()
{/*
	if(RecordGridInfoTool::recordGridInfoToDB()==true) {
		::MessageBox(NULL,_T("��ϲ����������Ϣ¼��ɹ�!"),_T("¼����Ϣ��ʾ"),MB_OK);
	}*/
}


void CGProjectDemo2View::OnOpenbsxls()
{
	//int* p = new int;
	// TODO: �ڴ�����������������
	CString OpenFilter = _T("��վ�ļ�(*.csv)|*.csv;*.CSV|�����ļ�(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		CString FileName = FileDlgOpen.GetPathName();
		CString FilePartName = FileDlgOpen.GetFileTitle();
		//�����ԭ�е����ݿ���Ϣ
		bool flag = RecordAreaInfoTool::insertAreaInfo(FileName);
		if(flag) {
			MessageBox(_T("��ϲ������վ����¼��ɹ�!"),_T("֪ͨ"),MB_OK);
		} else {
			MessageBox(_T("�ܱ�Ǹ����վ����¼��������!"),_T("֪ͨ"),MB_OK);
		}
	}
}


void CGProjectDemo2View::OnModify()
{
	// TODO: �ڴ�����������������
/*
	double raw[5]={1.2,1.3,1.5,1.4,1.7};
	double rawPart[2]={1.2,1.4};
	double lt[2]={1.3,1.6};
	double final[5];
	vector<double> finalVector=ModifyLTTool::getArrayModifyData(raw,ARRAYSIZE(raw),rawPart,ARRAYSIZE(rawPart),lt,ARRAYSIZE(lt));
	cout<<"haha"<<endl;
	*/
//	ModifyLTTool::modiyData();
	MessageBox(_T("����У��ģ��ȡ����"),_T("֪ͨ"),MB_OK);
}


void CGProjectDemo2View::OnPutxy()
{
	// TODO: �ڴ�����������������
	PutXY::ChangeToXY();
	MessageBox(_T("��ϲ����XY�����Ѿ����!"),_T("֪ͨ"),MB_OK);
}




void CGProjectDemo2View::OnRecordrtdata()
{
	// TODO: �ڴ�����������������
	CString OpenFilter = _T("·���ļ�(*.xls,*.xlsx)|*.xls;*.XLS;*.xlsx;*.XLSX|�����ļ�(*.*)|*.*||");
	CFileDialog FileDlgOpen(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		CString FileName = FileDlgOpen.GetPathName();
		CString FilePartName = FileDlgOpen.GetFileTitle();
		//�����ԭ�е����ݿ���Ϣ
		bool flag = RecordRTData::recordRTData(FileName);
		if(flag) {
			MessageBox(_T("��ϲ����·������¼��ɹ�!"),_T("֪ͨ"),MB_OK);
		} else {
			MessageBox(_T("�ܱ�Ǹ��·������¼��������!"),_T("֪ͨ"),MB_OK);
		}
	}
}


void CGProjectDemo2View::OnCalculate()
{
	// TODO: �ڴ�����������������
	//�����ņ���ģ�飬���г�ǿ�ļ���
	GetStrongestStrength::getStrongestStrength();
	MessageBox(_T("��ϲ�����������ݳɹ�!"),_T("֪ͨ"),MB_OK);
}


void CGProjectDemo2View::OnGridmif()
{
	// TODO: �ڴ�����������������
	CString OpenFilter = _T("�����ļ�(*.mif)|*.mif;*.MIF|�����ļ�(*.*)|*.*||");
	CFileDialog FileDlgOpen(FALSE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, OpenFilter);
	if(IDOK == FileDlgOpen.DoModal())
	{
		CString FileName = FileDlgOpen.GetPathName();
		string fileNameString = FileName.GetBuffer(0);
		fileNameString.append(".mif"); 
		//����ǿֵ����ɫ���ж�Ӧ�ĸı�
		SetGridColorTool::SetColor();
		MessageBox(_T("��ϲ������ɫ��Ϣ�Ѿ�ת���ɹ�!"),_T("֪ͨ"),MB_OK);
		//�����ݿ���ȡ���������ɫ��Ϣ����չʾ
		MakeGridFileTool::makeGridFile(fileNameString);
		MessageBox(_T("��ϲ�����Ѿ���������MIF�ļ�!"),_T("֪ͨ"),MB_OK);
	}
}


void CGProjectDemo2View::OnChange()
{
	// TODO: �ڴ�����������������
	clock_t startTime = GetTickCount();
	GridBSDistanceCal::updateDistance();
	clock_t endTime = GetTickCount();
	DWORD lastTime = endTime-startTime;
	cout<<lastTime;
	MessageBox(_T("�������"),_T("֪ͨ"),MB_OK);

}