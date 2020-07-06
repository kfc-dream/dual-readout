#ifndef DRparamBarrel_h
#define DRparamBarrel_h 1

#include "TVector3.h"
#include "DD4hep/DetFactoryHelper.h"

#include <vector>
#include <cmath>

namespace ddDRcalo {
  class DRparamBarrel {
  public:
    DRparamBarrel();
    ~DRparamBarrel();

    void SetIsRHS(bool isRHS) { fIsRHS = isRHS; }
    void SetInnerX(double innerX) { fInnerX = innerX; }
    void SetTowerH(double towerH) { fTowerH = towerH; }
    void SetNumZRot(int num) { fNumZRot = num; fPhiZRot = 2*M_PI/(double)num; }
    void SetDeltaTheta(double theta) { fDeltaTheta = theta; }
    void SetThetaOfCenter(double theta) { fThetaOfCenter = theta; }
    void SetPMTT(double PMTT) { fPMTT = PMTT; }

    bool GetIsRHS() { return fIsRHS; }
    double GetCurrentInnerR() { return fCurrentInnerR; }
    TVector3 GetV1() { return fV1; }
    TVector3 GetV2() { return fV2; }
    TVector3 GetV3() { return fV3; }
    TVector3 GetV4() { return fV4; }
    double GetH1() { return fCurrentInnerHalf; }
    double GetBl1() { return fV3.X()*std::tan(fPhiZRot/2.); }
    double GetTl1() { return fV1.X()*std::tan(fPhiZRot/2.); }
    double GetH2() { return fCurrentOuterHalf; }
    double GetBl2() { return fV4.X()*std::tan(fPhiZRot/2.); }
    double GetTl2() { return fV2.X()*std::tan(fPhiZRot/2.); }

    TVector3 GetTowerCenter(int numPhi);

    TVector3 GetSipmLayerCenter(int numPhi);

    dd4hep::Transform3D GetTransform3D(int numPhi);

    void init();

  private:
    bool fIsRHS;
    double fPhiZRot;
    double fInnerX;
    double fTowerH;
    int fNumZRot;
    double fDeltaTheta;
    double fThetaOfCenter;
    double fCurrentInnerR;
    TVector3 fCurrentCenter;
    TVector3 fV1;
    TVector3 fV2;
    TVector3 fV3;
    TVector3 fV4;
    double fPMTT;

    double fInnerY;
    double fCurrentInnerHalf;
    double fCurrentOuterHalf;
  };
}

#endif