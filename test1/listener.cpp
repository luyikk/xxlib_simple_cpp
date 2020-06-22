#include "listener.h"
#include "peer.h"
void Listener::Accept(std::shared_ptr<Peer> peer) {
    peer->Hold();
    peer->SetTimeoutSeconds(30);
}
