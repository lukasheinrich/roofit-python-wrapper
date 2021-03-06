/***************************************************************************** 
 * RooPyWrapper
 * author: Kyle Cranmer <kyle.cranmer@nyu.edu>
 * author: Lukas Heinrich
 *                                                                          * 
 * This is an example RooAbsReal that makes a call back to python code
 *****************************************************************************/ 

#ifndef ROOPYWRAPPER
#define ROOPYWRAPPER

#include "RooAbsReal.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"

#ifndef __CINT__
#include "Python.h"
#endif

#ifndef PyObject_HEAD
struct _object;
typedef _object PyObject;
#endif


class RooPyWrapper : public RooAbsReal{
public:
  RooPyWrapper() {} ; 
  RooPyWrapper(const char *name, const char *title, RooAbsReal& _features);
  RooPyWrapper(const RooPyWrapper& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooPyWrapper(*this,newname); }
  inline virtual ~RooPyWrapper() { }

  void RegisterCallBack( PyObject* pyobject );


protected:

  virtual Double_t evaluate() const ;

private:
  RooRealProxy features ;  

  PyObject* m_callback;
  ClassDef(RooPyWrapper,1); // Your description goes here...
};
 
#endif
