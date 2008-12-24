#pragma once

#ifdef _WIN32_WCE
#error "CDHtmlDialog is not supported for Windows CE."
#endif 

#include "..\..\filters\switcher\AudioSwitcher\AudioSwitcher.h"
// CUESettingPanel dialog

class CUESettingPanel : public CDHtmlDialog
{
	DECLARE_DYNAMIC(CUESettingPanel)
	virtual HRESULT STDMETHODCALLTYPE  GetHostInfo(DOCHOSTUIINFO *pInfo);
	virtual HRESULT STDMETHODCALLTYPE  ShowContextMenu(DWORD /*dwID*/, POINT *ppt, IUnknown* /*pcmdtReserved*/, IDispatch* /*pdispReserved*/);
	void ApplyAllSetting();
	void ApplyGeneralSetting();
	void ApplyVideoSetting();
	void ApplyAudioSetting();
	void ApplySubSetting();
	void ApplyFileAsscSetting();
	void ApplyHotkeySetting();
	int m_sgi_chkremwinpos;
	int m_sgi_chkcdromenu;
	int m_sgi_chkuseini;
	int m_sgi_chkfileass;
	int m_sgi_chkplayrepeat;
	int m_sgi_chkexitfullscreen;
	int m_sgi_chkabnormal;
	int m_sgi_chkautoplay;
	CString m_sgs_initblock;
	CString m_sgi_startupcheckexts;
	CString m_sgs_videorender;
	long m_sgi_videorender;
	int m_sgi_lockbackbuff;

	int m_sgi_normalize;
	int m_sgi_downsample44k;

	long m_sgi_channelsetting;
private:
	CComQIPtr<IAudioSwitcherFilter> m_pASF;
public:
	CUESettingPanel(IFilterGraph* pFG, CWnd* pParentWnd, UINT idPagein);   // standard constructor
	virtual ~CUESettingPanel();
// Overrides
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);
	HRESULT OnButtonApply(IHTMLElement *pElement);
	HRESULT OnButtonAdvanceSetting(IHTMLElement *pElement);
	bool bOpenAdvancePanel;
	int idPage;
// Dialog Data
	enum { IDD = IDD_DHTML_SETTING, IDH = IDR_HTML_UESETTINGPANEL };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
};
