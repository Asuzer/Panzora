
// PanzoraView.cpp : CPanzoraView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPanzoraView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPanzoraView 构造/析构

CPanzoraView::CPanzoraView()
{
	// TODO: 在此处添加构造代码

}

CPanzoraView::~CPanzoraView()
{
}

BOOL CPanzoraView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPanzoraView 绘制

void CPanzoraView::OnDraw(CDC* /*pDC*/)
{
	CPanzoraDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPanzoraView 打印


void CPanzoraView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPanzoraView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPanzoraView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPanzoraView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CPanzoraView 诊断

#ifdef _DEBUG
void CPanzoraView::AssertValid() const
{
	CView::AssertValid();
}

void CPanzoraView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPanzoraDoc* CPanzoraView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPanzoraDoc)));
	return (CPanzoraDoc*)m_pDocument;
}
#endif //_DEBUG


// CPanzoraView 消息处理程序
