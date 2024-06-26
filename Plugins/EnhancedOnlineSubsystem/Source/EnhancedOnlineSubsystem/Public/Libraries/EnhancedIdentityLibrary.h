// Copyright © 2024 MajorT. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "EnhancedSessionsLibrary.h"
#include "EnhancedIdentityLibrary.generated.h"


class UEnhancedOnlineRequest_LoginUser;

/**
 * Delegate for when a login request succeeds
 * @param LocalUserIndex	The index of the local user who made the request
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FBPOnLoginRequestSuceeded, int32, LocalUserIndex);

/**
 * Library of functions for interacting with the Enhanced Online Subsystem
 */
UCLASS()
class ENHANCEDONLINESUBSYSTEM_API UEnhancedIdentityLibrary : public UEnhancedSessionsLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Add a player to the admin list of this session
	 * Please note that this needs to be implemented in the game session :)
	 * @param InPlayerController player to add to the list.
	 */
	UFUNCTION(BlueprintCallable, Category = "Online|EnhancedSessions|Management", meta = (DisplayName = "Add Admin"))
	static void K2_AddAdmin(APlayerController* InPlayerController);

	/**
	 * Remove a player from the admin list of this session
	 * Please note that this needs to be implemented in the game session :)
	 * @param InPlayerController player to remove from the list.
	 */
	UFUNCTION(BlueprintCallable, Category = "Online|EnhancedSessions|Management", meta = (DisplayName = "Remove Admin"))
	static void K2_RemoveAdmin(APlayerController* InPlayerController);

	/**
	 * Kick a player from the session
	 * @param InPlayerController player to kick
	 * @param KickReason reason for the kick
	 * @return true if the player was kicked
	 */
	UFUNCTION(BlueprintCallable, Category = "Online|EnhancedSessions|Management|Sessions", meta = (DisplayName = "Kick Player"))
	static bool K2_KickPlayer(APlayerController* InPlayerController, const FText KickReason);

	/**
	 * Ban a player from the session
	 * @param InPlayerController player to ban
	 * @param BanReason reason for the ban
	 * @return true if the player was banned
	 */
	UFUNCTION(BlueprintCallable, Category = "Online|EnhancedSessions|Management|Sessions", meta = (DisplayName = "Ban Player"))
	static bool K2_BanPlayer(APlayerController* InPlayerController, const FText BanReason);

	/**
	 * Change the player name
	 * @param InPlayerController player to change the name of
	 * @param NewName new name for the player
	 */
	UFUNCTION(BlueprintCallable, Category = "Online|EnhancedSessions|Management|Identity", meta = (DisplayName = "Change Player Name"))
	static void K2_ChangePlayerName(APlayerController* InPlayerController, const FString NewName);

public:
	/**
	 * Constructs a request to login an online user
	 * @param WorldContextObject	The world context object, IF YOU SEE THIS IN BLUEPRINTS, YOU ARE DOING SOMETHING WRONG >:(
	 * @param AuthType				The type of authentication to use
	 * @param AuthToken				The authentication token
	 * @param UserId		Additional data to send with the request
	 * @param LocalUserIndex		The index of the local user who made the request
	 * @param bInvalidateOnCompletion	Whether to invalidate the request when it's completed
	 * @param OnSucceededDelegate	Delegate to call when the request succeeds
	 * @param OnFailedDelegate		Delegate to call when the request fails
	 * @return The request object
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Online|EnhancedSessions|Identity", meta =
		(WorldContext = "WorldContextObject", Keywords = "Make, Create, New", DisplayName = "Construct Online Login User Request",
			AdvancedDisplay = "LocalUserIndex", LocalUserIndex = "0"))
	static UPARAM(DisplayName = "Request") UEnhancedOnlineRequest_LoginUser* ConstructOnlineLoginUserRequest(
		UObject* WorldContextObject,
		const EEnhancedLoginAuthType AuthType,
		const FString UserId,
		const FString AuthToken,
		const int32 LocalUserIndex,
		const bool bInvalidateOnCompletion,
		FBPOnLoginRequestSuceeded OnSucceededDelegate,
		FBPOnRequestFailedWithLog OnFailedDelegate);


public:
};
