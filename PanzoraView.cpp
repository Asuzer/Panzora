
// PanzoraView.cpp : CPanzoraView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Panzora.h"
#endif

#include "PanzoraDoc.h"
#include "PanzoraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPanzoraView

IMPLEMENT_DYNCREATE(CPanzoraView, CView)

BEGIN_MESSAGE_MAP(CPanzoraView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPanzoraView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPanzoraView ����/����

CPanzoraView::CPanzoraView()
{
	// TODO: �ڴ˴���ӹ������

}

CPanzoraView::~CPanzoraView()
{
}

BOOL CPanzoraView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPanzoraView ����

void CPanzoraView::OnDraw(CDC* /*pDC*/)
{
	CPanzoraDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPanzoraView ��ӡ


void CPanzoraView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPanzoraView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPanzoraView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPanzoraView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CPanzoraView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPanzoraView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPanzoraView ���

#ifdef _DEBUG
void CPanzoraView::AssertValid() const
{
	CView::AssertValid();
}

void CPanzoraView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPanzoraDoc* CPanzoraView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPanzoraDoc)));
	return (CPanzoraDoc*)m_pDocument;
}
#endif //_DEBUG


// CPanzoraView ��Ϣ�������
