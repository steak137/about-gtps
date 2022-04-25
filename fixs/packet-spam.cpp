//main.cpp
/*enet type receive*/

if (pData->lpps + 1000 < (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count()) {
					pData->pps = 0;
					pData->lpps = (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count();
				}
				else {
					pData->pps++;
					if (pData->pps >= 89) {
						enet_peer_disconnect_later(peer, 0);
						for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
							if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
						}
					}
				}


/*player.h*/
/*playerinfo struct*/

int pps = 0;
long long lpps = 0;
