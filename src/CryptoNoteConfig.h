// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2016-2017 BXC developers
// Copyright (c) 2017 UltraNote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

//pragma once not working so using belo
#ifndef CRYPTONOTECONFIG
#define CRYPTONOTECONFIG

#include <cstdint>
#include <initializer_list>
#include <map>

namespace CryptoNote {

namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x1a2638; // addresses start with "Xun3"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2         = 6 * 60 * 2;
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE           = 10;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V2          = 11;

const uint64_t MONEY_SUPPLY				     = UINT64_C(8589869056000000000);

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 6;
// COIN - number of smallest units in one coin
const uint64_t POINT                                         = UINT64_C(1000);        // pow(10, 3)
const uint64_t COIN                                          = UINT64_C(1000000);     // pow(10, 6)
const uint64_t MINIMUM_FEE                                   = UINT64_C(1000);        // pow(10, 3)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100);         // pow(10, 2)

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;

const size_t   DIFFICULTY_WINDOW                             = 20;
const size_t   DIFFICULTY_CUT                                = 5;

const size_t   DIFFICULTY_WINDOW_V1                          = 35;
const size_t   DIFFICULTY_WINDOW_V2                          = 60;

const size_t   DIFFICULTY_LAG                                = 1; //not used in v1,v2


static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT                            = 1 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 22000; //~1 month
const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * 22000; //~1 year
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0; //rate is constant
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 3; //percentage rate for DEPOSIT_MAX_TERM
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR                             = 250; //early depositor multiplier
const uint32_t END_MULTIPLIER_BLOCK                          = 3600; //block at which the multiplier ceases to be applied

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); //seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); //seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint64_t UPGRADE_HEIGHT                                = 1;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(150) * parameters::COIN);
const uint64_t ICO_BLOCK_REWARD	                             = (UINT64_C(18446744073) * parameters::COIN); // 18.4 billion ICO
const uint64_t MAX_BLOCK_REWARD                              = (UINT64_C(1500) * parameters::COIN);
const uint64_t REWARD_INCREASE_INTERVAL                      = (UINT64_C(264000));

const char     CRYPTONOTE_NAME[]                             = "UltraNote";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff000180a3c347029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101677642503be486533f0aacb7ccce24a3d4931635fa700d62bf6b383cf26436e9";
const uint32_t GENESIS_NONCE                                 = 70;
const uint64_t GENESIS_TIMESTAMP                             = 1496764095;

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              = 63000;
const int      RPC_DEFAULT_PORT                              = 64000;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "0000000000000000000000000000000000000000000000000000000011111111";

const std::initializer_list<const char*> SEED_NODES = {
   "seed1.ultranote.org:63000",
   "seed2.ultranote.org:63000",
   "seed3.ultranote.org:63000",
   "seed4.ultranote.org:63000",
   "seed5.ultranote.org:63000",
   "seed6.ultranote.org:63000",
   "seed7.ultranote.org:63000",
   "seed8.ultranote.org:63000",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};


#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
 { 3700, "34126fea8a0168a41885358fa1f3d793a3a6d28e650da6cc9bc2de9d6ad5fc24" }, 
 { 9900, "15f3ecbb6324991c653ceed03619a735b40142d1b4777161593510f0f1d1a098" },
 { 22000, "8d444f19cc5cd46738583a001135a72b5824aa380e5006f422108eb50d9b9cca" },
 { 33000, "4e8958bcf1673bc326d6285c5f3df256f2c48c7ff85db7ef13637421a561e70e" },
 { 55000, "3da7429c64b8c0d4b2314ffe1a9df99bbda4a035196037f3f7f4f397ba3bac4c" },
 { 88000, "7edbe42a8a4ea71d8b77cc9dde78c9e6ac15cf6ca461a2e301a8a723de251373" },
 { 100000, "8f492fd39ce91174e65e5890560be8de5bc98b784b5067b3a20bf5a366524f6d" },
 
 //v2 checkponts
 { 114117, "250f9d28333fd3db9d0fad3ea2577c5f9ac3b85d85effcd666db39c2af8f03d8" },
 { 114118, "dc3f4e73ab4ef5b39aa43b55f34cb5597ac60f7d7d0e2978439b78c6db9e8487" },
 { 114119, "15431e8515f1c410af43dd34d60c844328852018fd88df0d96e25379f481731e" },
 { 114120, "2aded551461f15676f1caf24bdb1b464d840928232ff15a06d782ac671840e24" },
 { 114121, "4afd8c187955eca58ea0d208cef705677f976679266d202276cba57708ea07e9" },
 { 114122, "be98eae41b38a0aaaf9a10abff45d545b5e89453fa4cd5f1ac63e6e56730ec3d" },
 { 114123, "da1fb6075ee86ddc5bf62c1ba8c3a785b38e70cb34ba63cee4bc3685713feae7" },
 { 114124, "ae23b4e002d6ace6d7f3338ca767a5af959cd317ddaa1af7326b39b1f398d15c" },
 { 114125, "692d44097f1965555da0d6198c79c72bd5ebc8175553531f92ef1287b1d6d7de" },
 { 114126, "01ab8f89ff810af1407ebff6d3951184d84b4ed8fe6881a04ebe48f402fa6ee3" },
 { 114127, "9db4950326d3bfc8d6db40d22017a0afd0ef69044a6ae807b8c3a43c2042d9c0" },
 { 114540, "1efdb6d9265c3138213eb2b733fca9a3d33c474a4b9286b561c96b3017082a32" },
 { 114560, "eab548a8102fa6ef6fe50c7f8ac3954e12db472ca5b1da2722cf4d4a59f5e32f" },
 { 114580, "c970dcf9a4a5c78642c7aa7b7daff0b395d6323557cf54b96190fa7f41a37952" },
 { 114684, "179c80e9ca15b11e59df5970c92a82326618a94f256fc7ad9669899c87bebdb2" },
 { 114685, "289cd8188f58306af953a099d2fadba5647711bbc77102ade4dbc607d973aa09" },
 { 114686, "6a634121bd4c63198d924237501383a51b5491e30fa57a7aa6d41a13512ddc3c" },
 { 114687, "ca74f18e54b1e0c8c623ca4956d90bb4620f03dcc858189161eaf16ce5840bd4" },
 { 114688, "6b7283c86bd5509619dcc63d1f3da1ed884db3fe3fbafaf310407b35507a6ff1" },
 { 114689, "2a270477326bfc0bcd7d394f924a206e9f2e1ecddcaa145b0abf11e147103224" },
 { 114745, "ee42567b0027ed982775ff10cf21f1849d04fed1263c32be9abe8301e1db78fa" },
 { 114750, "dc02f008cf4d16f4a9b6c8246b8f4f28b8ef0ac854d62a685da39507f2c7dc93" },
 { 114760, "94b906bf900980ba05a611410842fa0aaa7673df6f95239de36d3b7f8f8aa82c" },
 { 114770, "39dc9a5466741a8a04782059926b3d9b2c11c784c4f5b8bb90085bb56724e1d4" },
 { 115000, "2e3686d4371be0e80b55f860ab506dc3172117a41a63fd9ad4787153937b0d69" },
 { 115001, "274ab9f4167c8a67808cc2ce0d916db4c7700196ccc404799d41d4545043a9b9" },
 { 153702, "5eb63d86e6afa2910b7b6ebb66e947031979af30b333a87b6737eaff45c0db1a" },
 { 155147, "6fe27d8f59ada032434dfbcf23d8e4769473e94c8fb5e468f5ae428331739c0d" },
 { 158478, "3057adb5cbe3af55a2b78c1b54d19d609157e2e2e8e49bb02e2f44f1a1e020f9" },
 { 162313, "8efa9ad5e1f2bdbbd1aa3ec3f1217781fba960da803bdc024b5f3a39e4bb180a" },
 { 162325, "3e509771b3e0b06e851843b8ff651a790c9f46fc1b6648d53bd73901a1886166" },
 { 162338, "bde957d99a09f70925e02f535a2dfe63274c0c2e18f936bda9aadd9c6b3ba6da" },
 { 162340, "a7726d8f86ff67a8d66f665d65013a04a6e2dc5c650d02b5999842b9ef9e95e1" },
 { 162342, "ccc56b74cc2b55802cba745f809f4b344eb447006d8bef5302bf8597337a0d92" },
 { 162344, "5ca60da58572627913aa7dac32d6985e96b4b431aa4077e3d193a76b03f7a5d7" },
 //
 
 { 164332, "577cf64d91d3637ce6d11ab115b33214908f5ce579d3c3e05f916184db901b2d" },
 { 164350, "db9043b38796f3f700f54d14c00a37c5fff3702c73402d190cb6a5fc67fd9e18" },
 { 164382, "7eedbf762f926f5db4416683b8e19dc93c69176778077c5706c70fc79a3d3b6e" },
 { 164433, "0d6f935c0b0d1ccfa285f8ba74d572a80f391ff4d94ee84f1e5f83f3495d3112" },
 { 164459, "898caac3efdc7fb053efd35141293b6b7837209f29fddb76050237ee6fbf6b73" },
 { 164465, "0068e371e6c135ec770a9af696b2c51a680108fdcc8cc7abc3eb330d8d82f6cd" },
 { 164503, "de012fe2a7741fec20d77d23cc9a2b2322c9c5ccb96e91bf0734dc3f8fc9d70e" },
 { 114124, "ae23b4e002d6ace6d7f3338ca767a5af959cd317ddaa1af7326b39b1f398d15c" },
 { 114125, "692d44097f1965555da0d6198c79c72bd5ebc8175553531f92ef1287b1d6d7de" },
 { 114126, "01ab8f89ff810af1407ebff6d3951184d84b4ed8fe6881a04ebe48f402fa6ee3" },
 { 114127, "9db4950326d3bfc8d6db40d22017a0afd0ef69044a6ae807b8c3a43c2042d9c0" },
 { 114540, "1efdb6d9265c3138213eb2b733fca9a3d33c474a4b9286b561c96b3017082a32" },
 { 114560, "eab548a8102fa6ef6fe50c7f8ac3954e12db472ca5b1da2722cf4d4a59f5e32f" },
 { 114580, "c970dcf9a4a5c78642c7aa7b7daff0b395d6323557cf54b96190fa7f41a37952" },
 { 114684, "179c80e9ca15b11e59df5970c92a82326618a94f256fc7ad9669899c87bebdb2" },
 { 114685, "289cd8188f58306af953a099d2fadba5647711bbc77102ade4dbc607d973aa09" },
 { 114686, "6a634121bd4c63198d924237501383a51b5491e30fa57a7aa6d41a13512ddc3c" },
 { 114687, "ca74f18e54b1e0c8c623ca4956d90bb4620f03dcc858189161eaf16ce5840bd4" },
 { 114688, "6b7283c86bd5509619dcc63d1f3da1ed884db3fe3fbafaf310407b35507a6ff1" },
 { 114689, "2a270477326bfc0bcd7d394f924a206e9f2e1ecddcaa145b0abf11e147103224" },
 { 114745, "ee42567b0027ed982775ff10cf21f1849d04fed1263c32be9abe8301e1db78fa" },
 { 114750, "dc02f008cf4d16f4a9b6c8246b8f4f28b8ef0ac854d62a685da39507f2c7dc93" },
 { 114760, "94b906bf900980ba05a611410842fa0aaa7673df6f95239de36d3b7f8f8aa82c" },
 { 114770, "39dc9a5466741a8a04782059926b3d9b2c11c784c4f5b8bb90085bb56724e1d4" },
 { 115000, "2e3686d4371be0e80b55f860ab506dc3172117a41a63fd9ad4787153937b0d69" },
 { 115001, "274ab9f4167c8a67808cc2ce0d916db4c7700196ccc404799d41d4545043a9b9" },
 { 153702, "5eb63d86e6afa2910b7b6ebb66e947031979af30b333a87b6737eaff45c0db1a" },
 { 155147, "6fe27d8f59ada032434dfbcf23d8e4769473e94c8fb5e468f5ae428331739c0d" },
 { 158478, "3057adb5cbe3af55a2b78c1b54d19d609157e2e2e8e49bb02e2f44f1a1e020f9" },
 { 162313, "8efa9ad5e1f2bdbbd1aa3ec3f1217781fba960da803bdc024b5f3a39e4bb180a" },
 { 162325, "3e509771b3e0b06e851843b8ff651a790c9f46fc1b6648d53bd73901a1886166" },
 { 162338, "bde957d99a09f70925e02f535a2dfe63274c0c2e18f936bda9aadd9c6b3ba6da" },
 { 162340, "a7726d8f86ff67a8d66f665d65013a04a6e2dc5c650d02b5999842b9ef9e95e1" },
 { 162342, "ccc56b74cc2b55802cba745f809f4b344eb447006d8bef5302bf8597337a0d92" },
 { 162344, "5ca60da58572627913aa7dac32d6985e96b4b431aa4077e3d193a76b03f7a5d7" },
 
};

// {BlockIndex , Version}
const std::map<const uint32_t, const uint8_t> Version = {
    {34147, 1},
    {115000, 2},
	{170000, 3},
};

// {BlockIndex , Version}
const std::map<const uint32_t, const uint8_t> TestNetVersion = {
    {120, 1},
    {250, 2},
};

// {BlockIndex , Hash}
const std::map<const uint32_t, const char*> VersionCheck = {
    {34147, "cdc7e1b2bb3df0d48d271b7f8429a847ca661a112ce5ed5898b429983e257082"}
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS

#endif
