//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabInsightsInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::InsightsModels;

UPlayFabInsightsInstanceAPI::UPlayFabInsightsInstanceAPI()
{
}

UPlayFabInsightsInstanceAPI::UPlayFabInsightsInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabInsightsInstanceAPI::UPlayFabInsightsInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabInsightsInstanceAPI::UPlayFabInsightsInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabInsightsInstanceAPI::~UPlayFabInsightsInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabInsightsInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabInsightsInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabInsightsInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabInsightsInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabInsightsInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabInsightsInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabInsightsInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = MakeSharedUObject<UPlayFabAuthenticationContext>();

    return this->authContext;
}

bool UPlayFabInsightsInstanceAPI::GetDetails(
    const FGetDetailsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{ 
    InsightsModels::FInsightsEmptyRequest emptyRequest = InsightsModels::FInsightsEmptyRequest();
    return UPlayFabInsightsInstanceAPI::GetDetails(emptyRequest, SuccessDelegate, ErrorDelegate);
}

bool UPlayFabInsightsInstanceAPI::GetDetails(
    InsightsModels::FInsightsEmptyRequest& request,
    const FGetDetailsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Insights/GetDetails")) : this->settings->GetUrl(TEXT("/Insights/GetDetails")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsInstanceAPI::OnGetDetailsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsInstanceAPI::OnGetDetailsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetDetailsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetDetailsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsInstanceAPI::GetLimits(
    const FGetLimitsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{ 
    InsightsModels::FInsightsEmptyRequest emptyRequest = InsightsModels::FInsightsEmptyRequest();
    return UPlayFabInsightsInstanceAPI::GetLimits(emptyRequest, SuccessDelegate, ErrorDelegate);
}

bool UPlayFabInsightsInstanceAPI::GetLimits(
    InsightsModels::FInsightsEmptyRequest& request,
    const FGetLimitsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Insights/GetLimits")) : this->settings->GetUrl(TEXT("/Insights/GetLimits")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsInstanceAPI::OnGetLimitsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsInstanceAPI::OnGetLimitsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetLimitsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetLimitsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsInstanceAPI::GetOperationStatus(
    InsightsModels::FInsightsGetOperationStatusRequest& request,
    const FGetOperationStatusDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Insights/GetOperationStatus")) : this->settings->GetUrl(TEXT("/Insights/GetOperationStatus")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsInstanceAPI::OnGetOperationStatusResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsInstanceAPI::OnGetOperationStatusResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetOperationStatusDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetOperationStatusResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsInstanceAPI::GetPendingOperations(
    InsightsModels::FInsightsGetPendingOperationsRequest& request,
    const FGetPendingOperationsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Insights/GetPendingOperations")) : this->settings->GetUrl(TEXT("/Insights/GetPendingOperations")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsInstanceAPI::OnGetPendingOperationsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsInstanceAPI::OnGetPendingOperationsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetPendingOperationsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsGetPendingOperationsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsInstanceAPI::SetPerformance(
    InsightsModels::FInsightsSetPerformanceRequest& request,
    const FSetPerformanceDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Insights/SetPerformance")) : this->settings->GetUrl(TEXT("/Insights/SetPerformance")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsInstanceAPI::OnSetPerformanceResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsInstanceAPI::OnSetPerformanceResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetPerformanceDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsOperationResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabInsightsInstanceAPI::SetStorageRetention(
    InsightsModels::FInsightsSetStorageRetentionRequest& request,
    const FSetStorageRetentionDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Insights/SetStorageRetention")) : this->settings->GetUrl(TEXT("/Insights/SetStorageRetention")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabInsightsInstanceAPI::OnSetStorageRetentionResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabInsightsInstanceAPI::OnSetStorageRetentionResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetStorageRetentionDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    InsightsModels::FInsightsOperationResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
