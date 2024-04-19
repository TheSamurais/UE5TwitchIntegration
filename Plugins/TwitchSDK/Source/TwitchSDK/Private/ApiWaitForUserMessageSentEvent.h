// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TwitchSDKStructs.h"

#include "ApiWaitForUserMessageSentEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAsyncDoneApiWaitForUserMessageSentEvent, FTwitchSDKUserMessageSentEvent, Result, FString, Error);

/**
 * 
 */
UCLASS(meta = (HideThen = true))
class UApiWaitForUserMessageSentEvent : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	FTwitchSDKEventStreamDesc Desc;

public:
    UPROPERTY(BlueprintAssignable)
    FAsyncDoneApiWaitForUserMessageSentEvent Done;
    UPROPERTY(BlueprintAssignable)
    FAsyncDoneApiWaitForUserMessageSentEvent Error;

    virtual void Activate() override;

    /**
     * A specified channel chat receives a message.
     *
     * You may only call this with a subscription for the correct event type.
     *
     * @param desc An object describing the subscription.
     */
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "Twitch")
    static UApiWaitForUserMessageSentEvent* WaitForUserMessageSentEvent(FTwitchSDKEventStreamDesc desc);
};
