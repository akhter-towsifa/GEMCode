#ifndef GEMCode_GEMValidation_RPCDigiMatcher_h
#define GEMCode_GEMValidation_RPCDigiMatcher_h

/**\class DigiMatcher

 Description: Matching of Digis for SimTrack in RPC

 Original Author:  Sven Dildick
*/

#include "GEMCode/GEMValidation/interface/DigiMatcher.h"

#include "DataFormats/Common/interface/DetSetVector.h"
#include <DataFormats/RPCDigi/interface/RPCDigiCollection.h>

#include <vector>
#include <map>
#include <set>

typedef std::vector<RPCDigi> RPCDigiContainer;

class SimHitMatcher;

class RPCDigiMatcher : public DigiMatcher
{
public:

  RPCDigiMatcher(SimHitMatcher& sh);
  
  ~RPCDigiMatcher();

  // partition RPC detIds with digis
  std::set<unsigned int> detIds() const;

  // chamber detIds with digis
  std::set<unsigned int> chamberIds() const;


  // RPC digis from a particular partition, chamber or superchamber
  const DigiContainer& digisInDetId(unsigned int) const;
  const DigiContainer& digisInChamber(unsigned int) const;

  /// How many pads in RPC did this simtrack get in total?
  int nStrips() const;

  int extrapolateHsfromRPC(unsigned int, int) const; 

  
  std::set<int> stripsInDetId(unsigned int) const;

  // what unique partitions numbers with digis from this simtrack?
  std::set<int> partitionNumbers() const;

private:

  void matchDigisToSimTrack(const RPCDigiCollection& digis);

  std::vector<edm::InputTag> rpcDigiInput_;

  int minBXRPC_, maxBXRPC_;

  int matchDeltaStrip_;

  std::map<unsigned int, DigiContainer> detid_to_digis_;
  std::map<unsigned int, DigiContainer> chamber_to_digis_;

  bool verboseDigi_;
  bool runRPCDigi_;
};

#endif