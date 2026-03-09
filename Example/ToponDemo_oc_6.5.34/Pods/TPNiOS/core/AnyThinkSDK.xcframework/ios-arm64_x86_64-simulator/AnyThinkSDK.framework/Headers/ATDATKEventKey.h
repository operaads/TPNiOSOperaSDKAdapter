//
//  ATDATKEventKey.h
//  AnyThinkSDK
//
//  Created by li zhixuan on 2024/5/23.
//  Copyright © 2024 AnyThink. All rights reserved.
//

#ifndef ATAgentEventKey_h
#define ATAgentEventKey_h

#define AT_PSID_AG kATPSIDSessionIDKey
#define AT_DUA_AG @"1004657"

//desc
#define kATAgentEventExtraInfoRequestHeaderBiddingFlagKey @"header_bidding_flag"
#define kATAgentEventExtraInfoRequestPriceKey @"price"

#define kATTrackerExtraUnitIDKey @"unit_group_unit_id"

#define kATReadyToShowNotificationUserInfoPriority  @"priority"

#pragma mark - TK
#define kATTrackerExtraADKey @"extra_ad"

#define kATReadyToShowNotificationUserInfoPlacementModel  @"placement_model"

#define kATReadyToShowNotificationUserInfoRequestID  @"request_id"

#define kATTrackerExtraAdmobIlrdKey  @"am_ilrd"
#define kATTrackerExtraAdmobBidPriceTypeKey  @"am_bp_type"

#define kATTrackerExtraSortPriorityLevelKey  @"s_pty"

#define kATTrackerExtraShownNetworkPriorityInfoKey  @"priority_info"

#define kATTrackerExtraAgainLookFlagKey  @"again_look"
#define kATTrackerExtraLoadSuccessRetryFlagKey  @"auto_req"

#define kATTrackerExtraErrorKey  @"error_info"
#define kATTrackerExtraResourceTypeKey  @"resource_type"
#define kATTrackerExtraSDKCalledFlagKey  @"sdk_called_flag"
#define kATTrackerExtraSDKNotCalledReasonKey  @"sdk_not_called_reason"
#define kATTrackerExtraNetworkFirmIDKey  @"nw_firm_id"
#define kATTrackerExtraADASIDKey  @"asid"
#define kATTrackerExtraUNITIDKey  @"unitid"

//#define kATAdLoadingExtraRefreshFlagKey  kATAdLoadingExtraRefreshFlagKey//for banner&native banner refresh
#define kATTrackerExtraDefaultLoadFlagKey  @"default_load"
#define kATTrackerExtraFilledWithinNetworkTimeoutFlagKey  @"filled_within_network_timeout"
#define kATTrackerExtraFillRequestFlagKey  @"flag"
#define kATTrackerExtraFillTimeKey  @"filledtime"
#define kATTrackerExtraDataFillTimeKey  @"data_ft"
#define kATTrackerExtraASResultKey  @"as_result"
#define kATTrackerExtraAppIDKey  @"app_id"
#define kATTrackerExtraLastestRequestIDKey  @"new_req_id"
#define kATTrackerExtraLastestRequestIDMatchFlagKey  @"req_id_match"
#define kATTrackerExtraAdFilledByReadyFlagKey  @"filled_by_ready"
#define kATTrackerExtraAutoloadOnCloseFlagKey  @"auto_load_on_close"
#define kATTrackerExtraIsColdStartKey @"s_type"
#define kATTrackerExtraNetworkEncipherPriceKey @"en_p"
#define kATTrackerExtraBidReqDelayKey @"bid_req_delay_t"
#define kATTrackerExtraNetworkTransIDKey @"third_trans_id"
#define kATTrackerExtraNetworkNetworkPlIdKey @"network_pl_id"

#define kATTrackerExtraUGSptyCoefficientKey @"p_coef"

#define kATTrackerExtraLoadTimeKey  @"loadtime"
#define kATTrackerExtraClickAddressKey  @"click_address"
#define kATTrackerExtraMyOfferDefaultFalgKey  @"myoffer_showtype"
#define kATTrackerExtraOfferLoadedByAdSourceStatusFlagKey  @"loaded_by_ad_source_status_flag"
#define kATTrackerExtraAdObjectKey  @"ad_object"
#define kATTrackerExtraAdRenderWHKey  @"render_w_h"
#define kATTrackerExtraAdShowIntervalKey  @"pl_show_interval"
#define kATTrackerExtraAppShowIntervalKey  @"bidads_show_interval"
#define kATTrackerExtraAdClickIntervalKey  @"s_c_interval"

#define kATTrackerExtraAdShowSceneKey  @"scenario"
#define kATTrackerExtraAdShowCustomExtKey  @"show_custom_ext"
#define kATTrackerExtraAdShowSDKTimeKey  @"sdk_time"
#define kATTrackerExtraInfoTypeeKey  @"type"
#define kATTrackerExtraInfoPLIDeKey  @"pl_id"
#define kATTrackerExtraInfoREQIDeKey  @"req_id"
#define kATTrackerExtraImpTypeKey  @"imp_type"
#define kATTrackerExtraBDITTypeKey  @"bd_imp_type"
#define kATTrackerExtraTK24Key  @"notice"
#define kATTrackerExtraRotationOrderTK4TK6Key  @"rotation_order"
#define kATTrackerExtraRotationInterTK4TK6TK13Key  @"rotation_inter"
#define kATTrackerExtraRotationCountKey  @"rotation_count"
#define kATTrackerExtraRotationCloseCacheCountKey  @"rotation_close_cache_count"
#define kATTrackerExtraRotationCloseReasonKey  @"rotation_close_reason"


#define kATTrackerExtraTrafficGroupIDKey  @"traffic_group_id"
#define kATTrackerExtraUGUnitIDKey  @"ug_unit_id"
#define kATTrackerExtraASIDKey  @"as_id"
#define kATTrackerExtraFormatKey  @"ad_format"
#define kATTrackerExtraRequestExpectedOfferNumberFlagKey  @"req_expected_offer_num_flag"
#define kATTrackerExtraClickImpKey  @"cl_imp"
#define kATTrackerExtraPlacementModelKey  @"placement_model"
#define kATTrackerExtraAdCacheStatusKey  @"ad_ch_st"
#define kATTrackerExtraAdRequestUsedTimeKey  @"ad_reqt"
#define kATTrackerExtraAdTypeKey  @"ad_type"
#define kATTrackerExtraAdClickTypeKey  @"cl_s_type"
#define kATTrackerExtraAdClickAreaTypeKey  @"cl_area"
#define kATTrackerExtraRewardedVideoRenderVideoType  @"render_type_video"
#define kATTrackerExtralReqParTypeKey  @"req_par"
#define kATTrackerExtralReqParNumKey  @"req_par_num"
#define kATTrackerExtraOFMSystemKey  @"ofm_system"
#define kATTrackerExtraAdListTypeKey  @"ads_list_type"
#define kATTrackerExtraClientSideEcpmKey  @"e_c"
#define kATTrackerExtraServerKeyIdKey  @"e_c_key_id"
#define kATTrackerExtraUniqueIdKey  @"unique_id"
#define kATTrackerExtraAdxMtgMixTypeKey  @"adx_mtg_mix_type"

#define kATTrackerExtraBnnerHeightKey  @"bn_height"
#define kATTrackerExtraBnnerWidthKey  @"bn_width"
#define kATTrackerExtraBnnerTemplateIdKey  @"bn_template_id"
#define kATTrackerExtraBnnerClickAreaKey  @"bn_click_area"

#define kATTrackerExtraInterstitialStyleEnvelope  @"close_button_m"
#define kATTrackerExtraAdAssetsResourceMaterialTypeKey  @"material_type"
#define kATTrackerExtraAdxOfferInstallTypeKey  @"offer_install"
#define kATTrackerExtraShowSpecAdTypeKey  @"show_spec_nw_ad"
#define kATTrackerExtraShowNativeExpressIdsKey @"nv_tmpl_id"
#define kATTrackerExtraCloseButtonStyleKey  @"cls_style"
#define kATTrackerExtraInterTemplateIdKey  @"iv_template_id"

//tk3
#define kATTrackerExtraRecallFailedUnitIDStyleKey  @"unit_id"
#define kATTrackerExtraRecallFailedBidtypeStyleKey  @"bidtype"
#define kATTrackerExtraRecallFailedBidPriceStyleKey  @"bidprice"
#define kATTrackerExtraRecallFailedUnitTypeStyleKey  @"unit_type"
#define kATTrackerExtraRecallFailedCpPreMdStyleKey  @"cp_pre_md"


// tk25
#define kATTracker25_FROM_KEY  @"from"
#define kATTracker25_ISPLAYEND_KEY  @"is_playend"
#define kATTracker25_URL_KEY  @"url"
#define kATTracker25_STATUS_KEY  @"status"


#define kATTrackerExtraBidTokenMd5Key  @"bid_t_m"
#define kATTrackerExtraBidLinkKey  @"bid_link"

// tk28
#define kATTrackerExtraAdHasSendTk28TypeKey  @"tk_x_cl_sent"


#endif /* ATAgentEventKey_h */
