from ROOT import *
import ROOT
ROOT.RooStats
gSystem.Load( 'libRooFitPythonWrapper' )

def myFunction(x,a):
   #return x*x as an example
   return (x-0.5)**2 + (a-0.2)**2

x = RooRealVar('x','x',-1,1)
a = RooRealVar('a','a',-1,1)

s = RooPyWrapper('s','s',x,a)
s.RegisterCallBack( myFunction )

a.setVal(0.5)
# a.setConstant(True)
x.setVal(0.2)
print(s.getVal())


m = ROOT.RooMinimizer(s)

m.migrad()

# c1 = TCanvas('c1')
# frame = x.frame()
# s.plotOn(frame)
# frame.Draw()
# c1.SaveAs('RooPyWrapper.png')
