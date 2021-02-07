// STUploadDoc.h : CSTUploadDoc 类的接口
//


#pragma once
#include "stockdatalist.h"


class CSTUploadDoc : public CDocument
{
protected: // 仅从序列化创建
	CSTUploadDoc();
	DECLARE_DYNCREATE(CSTUploadDoc)

// 属性
public:

// 操作
protected:
	bool LoadData(CStdioFile& infile);
	

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CSTUploadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	CStockDataList m_DocList;
	CString m_strCurrentFund;
public:

	CStockDataList& GetDocList(void)
	{
		//TODO: insert return statement here
		return m_DocList;
	}

	CString GetCurrentFund(){return m_strCurrentFund;}
	void SetCurrentFund(CString strSet){m_strCurrentFund=strSet;}
	afx_msg void OnDataImport();
	virtual void DeleteContents();
};


