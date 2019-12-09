#include "JsonRequestPacketDeserializer.h"

JsonRequestPacketDeserializer::JsonRequestPacketDeserializer()
{
}

/*
This function deserialize the login message and assigns it into a new LoginRequset.
Input:string.
Output:LoginRequset.
*/
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::string buffer)
{
	json j = json::parse(buffer);
	LoginRequest login_request(j.at("_username").get<std::string>(), j.at("_password").get<std::string>());
	return login_request;
}
/*
This function deserialize the signup message and assigns it into a new SignUpRequset.
Input:string.
Output:SignUpRequset.
*/
SignUpRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::string buffer)
{
	json j = json::parse(buffer);
	SignUpRequest signup_request(j.at("_username").get<std::string>(), j.at("_password").get<std::string>(), j.at("_email").get<std::string>());
	return signup_request;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(std::string buffer)
{
	json j = json::parse(buffer);
	GetPlayersInRoomRequest get_players_in_room_request(j.at("room_id").get<unsigned int>());
	return get_players_in_room_request;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(std::string buffer)
{
	json j = json::parse(buffer);
	JoinRoomRequest join_room_request(j.at("room_id").get<unsigned int>());
	return join_room_request;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(std::string buffer)
{
	json j = json::parse(buffer);
	CreateRoomRequest create_room_request(j.at("room_name").get<std::string>(),j.at("max_users").get<unsigned int>(),j.at("question_count").get<unsigned int>(),j.at("answer_timeout").get<unsigned int>());
	return create_room_request;
}

SubmitAnswerRequest JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(std::string buffer)
{
	json j = json::parse(buffer);
	SubmitAnswerRequest submit_answer_request(j.at("answer_id").get<unsigned int>());
	return submit_answer_request;
}

