#ifndef OPERATIONSENUM_H
#define OPERATIONSENUM_H

/* NOTE that the 'maybe obsolete' enums could be replaced by functions
 * proper to the "waiting room" window */

enum ClientOperations
  {
    NEW_CLIENT, //maybe obsolete
    CONNECTION_REQUEST, //maybe obsolete
    CHAT_MESSAGE,
    PRIVATE_MESSAGE,
    CLAN_MESSAGE
  };

enum ServerOperations
  {
    BROADCAST_CLIENT_CONNECTION, //maybe obsolete
    CONNECTION_ACCEPTED, //maybe obsolete
    CONNECTION_REFUSED, //maybe obsolete
    BROADCAST_CHAT_MESSAGE,
    BROADCAST_PRIVATE_MESSAGE,
    BROADCAST_CLAN_MESSAGE
  };
    
#endif //OPERATIONSENUM_H
