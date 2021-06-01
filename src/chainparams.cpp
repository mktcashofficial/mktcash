// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2019 The Mktcash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x00000edb03823e6b6fb39e27b3a6dfb9a80111fb9fb02980cc0096ceb588a8e7"))
    (200097, uint256("0x6037c7fbfc50d0801cb519d1f86cb56d5c3ba366a4837a4055da727944d68d01"))
    (200089, uint256("0x80fced71ebd01025fc44693dd59c4b96773291b60a513fc5a9d1cd1cfd57a7f5"))
    (200076, uint256("0x5d6d65614f629bdf8041d39e12fd8f9330efc1332754ece7cdc5490794f29d47"))
    (200055, uint256("0x3ce53592ef8aad4ea079d380e9e069b20f20630a8091099fd3a7737cce7a042f"))
    (200021, uint256("0xdb4089e461dc18437d5528e4a3ea500e151d33cf5b077eb31f5b36df2d349f9f"))
    (199966, uint256("0x648d1b24f4a13185e2a5a9edb189739152f3eeb97bb2d1de1be782e0d120235d"))
    (199877, uint256("0x18f501424d66f0b0607815aa06b67dd5be429935dab5b669a350c48bfa00d1f6"))
    (199733, uint256("0x91690b9c6b7801c5c0b0a010ef661384906196e0797ae42d0087843af9d78e78"))
    (199500, uint256("0x237b9fd8fb7bb785ebf7a9f022310e302d8bbc81db4d6756b2432d5729856069"))
    (199123, uint256("0x1e65c232f3b450e8af34a2d0691c17dabc5131d52971b144f2a1b3d9e0f8a939"))
    (198513, uint256("0xc41c825545242e303f3c809b863388f727e631c505c32947555aa604ddf8d5ae"))
    (197526, uint256("0xf47d52708903752b738f7a6df8aacdc1fb9d34656eb07b5ee39547777e31dca2"))
    (195929, uint256("0x01f594d88fd7b519b3c38025c3d8ff4cc032afa956486ad32e7acc9ef62db21b"))
    (193345, uint256("0x5d67cd2d6da00a22ea5dd822c8be13128499cb81e4bfad97f1c3366f894c9332"))
    (189164, uint256("0x5078c639f5804fa8a47be5e8e7046ebb9c44370705464a897dcac4ee6a9457e2"))
    (182399, uint256("0xcb4281425144e77a46810dd1dd10f1bd404bcb995f558d63ab95425608d40424"))
    (171453, uint256("0x6447e52208f4a04c22b8a5c6d046eb5353c91f6c477d345cd9008a81d7e5a63f"))
    (153742, uint256("0xff2ba3bd2a6cb83696e4ee08f930367ccef5266842daa3d03ab8891114064c41"))
    (125085, uint256("0x0aa23deb111bfeb89097d637e681ce8fcad0336eb1c69d21c4eb9d1ab3527c41"))
    (78717, uint256("0x9ce0e66a0df6ff7af785d0369201a5bdf6462bcf1515ee996a853fbcf095ab58"))
    (3692, uint256("0x863cb3ba5920f706fdcba4c3665c4acfea212ad7df354146814eedb07615000f"))
    ;

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1610161184, // * UNIX timestamp of last checkpoint block
    0,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1570470324,
    0,
    250
};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1570470444,
    0,
    100
};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x2d;
        pchMessageStart[1] = 0x22;
        pchMessageStart[2] = 0x21;
        pchMessageStart[3] = 0x2a;
        vAlertPubKey = ParseHex("043eb21c3fba131564544f746a9d0bd7003e63a0fee8c900bf1c63b3ac00f05134fc67c765a8f2e7ef691b645cd8fb5034eb3ca01c7b0541cd3aca8f6783a68ec5");
        nDefaultPort = 17223;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // MCH starting difficulty is 1 / 2^12
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // MCH: 1 day
        nTargetSpacing = 4 * 60;  // MCH: 1 minute
        nMaturity = 60;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 1000;
        nModifierUpdateBlock = 100;
        nEnforceNewSporkKey = 1610161184;
        nRejectOldSporkKey = 1610161184;

        const char* pszTimestamp = "Mktcash";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 250 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0466f8e042492f7e1be50f8fa84bc2d39d0cea242704d219bc6d9cd7d1e20c4abc105e45b0510396978c22a7e9f35d21d6fb10005fc27febc2851ba4f051411865") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1610161184;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1736228;

        hashGenesisBlock = genesis.GetHash();


        assert(hashGenesisBlock == uint256("0x00000edb03823e6b6fb39e27b3a6dfb9a80111fb9fb02980cc0096ceb588a8e7"));
        assert(genesis.hashMerkleRoot == uint256("0xfa8f6966680f28a067f037116d82b62998acc7a392e0a2bf32b57b33107ffb33"));

        vFixedSeeds.clear();

      vSeeds.push_back(CDNSSeedData("seed1", "node1.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("seed2", "node2.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("dns1", "dns1.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("dns2", "dns2.mktcash.org"));
      vSeeds.push_back(CDNSSeedData("dns3", "dns3.mktcash.org"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 110);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 115);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 238);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true; // Default true
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false; // Default false
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "043b13ed05f563af67811a5a1cf71b9353db587afec1c85347140d9ada637b956c56da5cfd8107eada9ca6238827fc220bd014b5a01f57375cfb85f3eb7625e6f7";
        strSporkKeyOld = "04dd7b7c4c6a683fec9586737dc12c0a6fa9ca7006d21dd570d540440f4c9de709ecb2320185f44cd6c4c22888433eae2d8edd6897a5da15475ed20eb34c991327";
        strObfuscationPoolDummyAddress = "mRffAwgPusif7NtezhsTXBQjwoS8sVreWF";
        nStartMasternodePayments = 1610161184;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xd0;
        pchMessageStart[1] = 0xcd;
        pchMessageStart[2] = 0xa9;
        pchMessageStart[3] = 0x96;
        vAlertPubKey = ParseHex("047702b6eb08ee32cfbd0cec8197e7287bc46aa3b9b855f268378a8e217eb1f7232dbca8f4e3459758ac2fd476a41266d8ce4ee19e3cacd5169802a9715bf572d1");
        nDefaultPort = 31244;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // MCH: 1 day
        nTargetSpacing = 1 * 60;  // MCH: 1 minute
        nLastPOWBlock = 100;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 101; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1570470324;
        genesis.nNonce = 1248594;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000031593b789b24efaa72a802fcc582f973d1d8871fb888dad1a951d0f1d57"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet mktcash addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet mktcash script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet mktcash BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet mktcash BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet mktcash BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04A8B319388C0F8588D238B9941DC26B26D3F9465266B368A051C5C100F79306A557780101FE2192FE170D7E6DEFDCBEE4C8D533396389C0DAFFDBC842B002243C";
        strSporkKeyOld = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x93;
        pchMessageStart[1] = 0x9f;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xd8;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // MCH: 1 day
        nTargetSpacing = 1 * 60;        // MCH: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;

        genesis.nTime = 1570470444;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 1;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 31246;
        //assert(hashGenesisBlock == uint256("0x55db4c46c531d7399537de526d10fddf1a36fbd7b270c721f0cd1a5e99743881"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 31248;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
