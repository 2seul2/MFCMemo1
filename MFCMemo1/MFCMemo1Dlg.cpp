
// MFCMemo1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCMemo1.h"
#include "MFCMemo1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCMemo1Dlg 대화 상자



CMFCMemo1Dlg::CMFCMemo1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMEMO1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCMemo1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_TB_MEMO1, strMemo);
	DDX_Control(pDX, IDC_TB_MEMO2, CMemo2);
	DDX_Control(pDX, IDC_TB_MEMO1, CMemo1);
}

BEGIN_MESSAGE_MAP(CMFCMemo1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST, &CMFCMemo1Dlg::OnBnClickedBtnTest)
	ON_COMMAND(ID_MENU_VIEW_LOWER, &CMFCMemo1Dlg::OnMenuViewLower)
	ON_COMMAND(ID_MENU_VIEW_UPPER, &CMFCMemo1Dlg::OnMenuViewUpper)
	ON_COMMAND(ID_MENU_EXIT, &CMFCMemo1Dlg::OnMenuExit)
END_MESSAGE_MAP()


// CMFCMemo1Dlg 메시지 처리기

BOOL CMFCMemo1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCMemo1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCMemo1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCMemo1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCMemo1Dlg::OnBnClickedBtnTest()
{
	static int Count = 0;   // 지역변수 : static 변수
	CString cs, cs1;
	char buf[1024];   // 배열
	char* sp = buf;
	char* str = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; *(str + i); i++)   // i < strlen(str)   // * == []
	{
		//char 배열 및 포인터를 이용한 경우
		sprintf(sp, " %02X", str[i]);   // 16진수로 표현
		while (*sp) sp++;

		// CStiring class 를 이용한 경우
		cs1.Format(" %02X", str[i]);   // 16진수로 표현
		cs += cs1;
	}
	CMemo2.SetWindowTextA(buf);
	CMemo2.SetWindowTextA(cs);

	//char* str = strMemo.GetBuffer();
	// 소문자 ==> 대문자  a~z  ==>  A~Z   :  가장 무지막지한 방법
	//                   (a~z) ==> (a~z)  -  0x20
	
	////int len = CMemo1.GetWindowTextA(buf, 1024);
	////if (Count % 2)   // 2 로 나누었을 때 나머지가 있는 경우 : 홀수인 경우
	////{
	////	for (int i = 0; i < len; i++)
	////	{
	////		if ((buf[i] >= 'a') && (buf[i] <= 'z')) buf[i] -= 0x20;   // 소문자를 대문자로 변환
	////	}
	////}
	////else            //                                      : 짝수인 경우
	////{
	////	for (int i = 0; i < len; i++)
	////	{
	////		if ((buf[i] >= 'A') && (buf[i] <= 'Z')) buf[i] += 0x20;   // 대문자를 소문자로 변환
	////	}
	////}

	CString cstr, s1;
	////CMemo1.GetWindowTextA(cstr);
	////if (((CButton*)GetDlgItem(IDC_RADIO1))->GetState() == true) s1 = cstr.MakeLower();
	////else if (((CButton*)GetDlgItem(IDC_RADIO2))->GetState() == true) s1 = cstr.MakeUpper();
	//////if (((CButton*)GetDlgItem(IDC_CHECK1))->GetState() == true) s1 = cstr.MakeLower();
	//////if (Count % 2 == 1) s1 = cstr.MakeLower();    // 소문자로 바꿔줌  // 원본 불면의 법칙(s1)
	//////else s1 = cstr.MakeUpper();                   // 대문자로 바꿔줌
	////CMemo2.SetWindowTextA(s1);
	Count++;
}


void CMFCMemo1Dlg::OnMenuViewLower()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString cstr, s1;
	CMemo1.GetWindowTextA(cstr);
	s1 = cstr.MakeLower();
	CMemo2.SetWindowTextA(s1);
}


void CMFCMemo1Dlg::OnMenuViewUpper()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString cstr, s1;
	CMemo1.GetWindowTextA(cstr);
	s1 = cstr.MakeUpper();
	CMemo2.SetWindowTextA(s1);
}


void CMFCMemo1Dlg::OnMenuExit()
{
	EndDialog(0);   // 해당 다이어로그를 끝냄
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
