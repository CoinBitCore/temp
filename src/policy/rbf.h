// Copyright (c) 2016-2017 The Coinbit Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINBIT_POLICY_RBF_H
#define COINBIT_POLICY_RBF_H

#include <txmempool.h>

static const uint32_t MAX_BIP125_RBF_SEQUENCE = 0xfffffffd;

enum RBFTransactionState {
    RBF_TRANSACTIONSTATE_UNKNOWN,
    RBF_TRANSACTIONSTATE_REPLACEABLE_BIP125,
    RBF_TRANSACTIONSTATE_FINAL
};

// Check whether the sequence numbers on this transaction are signaling
// opt-in to replace-by-fee, according to BIP 125
bool SignalsOptInRBF(const CTransaction &tx);

// Determine whether an in-mempool transaction is signaling opt-in to RBF
// according to BIP 125
// This involves checking sequence numbers of the transaction, as well
// as the sequence numbers of all in-mempool ancestors.
RBFTransactionState IsRBFOptIn(const CTransaction &tx, CTxMemPool &pool);

#endif // COINBIT_POLICY_RBF_H