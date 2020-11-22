open Css;

let primaryColor = orangered;
let baseGray = rgb(65, 65, 65);
let buttonBgGray = hex("333");
let borderGray = hex("444");
let selectionGray = gray;

let backgroundColor = rgb(33,33,33);
let maxContextWidth = px(900);
let primaryPaddingPx = 16;
let primaryPadding = px(primaryPaddingPx);

let nameSignSize = px(50);
let nameSignFontSize = px(32);
let nameFontSize = px(18);
let nameHMargin = px(12);

let navItemMargin = px(12);
let navItemFontSize = px(15);
let navMarginLeft = px(32);
let navMarginTop = px(4);
let navMarginRight = px(64);
let navMarginBottom = zero;

let introTextMaxBaseWidthPx = 500;
let introTextMaxBaseWidth = px(introTextMaxBaseWidthPx);
let introFontSize = px(16);
let introMarginTop = px(16);

let avatarBorderWidth = px(16);
let avatarBorderWidthPhone = px(10);
let avatarSizes = Media.define(
  ~smallPhone=[width(px(200)), height(px(200))],
  ~phone=[width(px(250)), height(px(250))],
  ~tablet=[width(px(300)), height(px(300))],
  ~laptop=[width(px(350)), height(px(350))],
  ~default=[width(px(400)), height(px(400))],
  ()
);

let helloLinkHoverTransform = translateY(px(-3));
let helloLinkImgSize = px(30);
let helloLinkMargin = px(2);

let ctaBlockVMargin = px(20);
let ctaBlockHMargin = zero;
let ctaButtonFontSize = px(15);
let ctaButtonBorderRadius = px(20);
let ctaButtonBorderWidth = px(3);
let ctaButtonVPadding = px(9);
let ctaButtonHPadding = px(26);
let ctaButtonVMargin = px(8);
let ctaButtonLeftMargin = zero;
let ctaButtonRightMargin = px(16);

let sCardWidth = px(160);
let sCardMargin = px(8);
let sCardBorderWidth = px(2);
let sCardBackgrounColor = buttonBgGray;
let sCardBorderColor = borderGray;
let sCardBorderRadius = px(10);
let sCardPadding = px(16);
let sCardHoverTransform = translateY(px(-4));
let sCardImgSize = px(64);
let sCardImgBorderRadius = px(8);
let sCardBottomMargin = px(8);

let sCompactCardWidth = px(96);
let sCompactCardMargin = px(7);
let sCompactCardPadding = px(8);
let sCompactCardFontSize = px(14);
let sCompactCardImgSize = px(32);
let sCompactCardImgBorderRadius = px(8);
let sCompactCardBottomMargin = px(4);

let journeyItemMargin = px(16);
let journeyItemImgSize = px(200);
let journeyItemImgBorderRadius = px(30);
let journeyItemPadding = px(20);
let journeyItemContentFontSize = px(15);

let projectTitleFontSize = px(26);
let iFrameContainerWidth = px(500);
let iFrameContainerHeight = px(350);
let projectDetailMarginBottom = px(16);
let projectDescriptionBackgrounColor = buttonBgGray;
let projectDescriptionBorderWidth = px(2);
let projectDescriptionBorderColor = borderGray;
let projectDescriptionBorderRadius = px(10);
let projectDescriptionPadding = px(24);
let projectDescriptionMarginLeft = px(24);
let projectDescriptionHeaderMarginBottom = px(16);
let projectDescriptionIconSize = px(16);
let projectDescriptionIconMarginRight = px(12);
let projectDescriptionIconDetailFontSize = px(15);
let projectDescriptionIconDetailMarginBottom = px(4);
let projectDescriptionDetailFontSize = px(14);
let projectDescriptionDetailVMargin = px(16);
let projectDescriptionStackCardBgColor = hex("666");
let projectDescriptionStackCardBorderRadius = px(4);
let projectDescriptionStackCardVPadding = px(4);
let projectDescriptionStackCardHPadding = px(8);
let projectDescriptionStackCardFontSize = px(14);
let projectDescriptionStackCardMargin = px(4);
let projectDescriptionStackCardFontColor = hex("ddd");
let projectTextDetailMarginTop = px(18);

let footerMarginTop = px(40);
let footerBorderWidth = px(1);
let footerBorderColor = borderGray;
let footerLinksMarginLeft = px(20);
let footerLinkColor = gray;
let footerLinkPadding = px(12);
let footerInfoVPadding = px(12);
let footerInfoLeftPadding = px(20);
let footerInfoRightPadding = px(32);
let footerInfoFontSize = px(15);

let seperatorVMargin = px(38);
let seperatorFontSize = px(30);
let seperatorUndescorePrimaryWidth = px(32);
let seperatorUndescorePrimaryHeight = px(4);
let seperatorUndescoreGrayWidth = px(128);
let seperatorUndescoreGrayHeight = px(4);
let seperatorUndescoreGrayColor = rgb(50, 50, 50);
let seperatorLinkPaddingLeft = px(4);

let imageDetailBackdropBgColor = rgba(0, 0, 0, 0.9);
let imageDetailButtonHPadding = px(24);
let imageDetailButtonVPadding = px(16);
let imageDetailButtonBgColor = rgba(0, 0, 0, 0.3);
let imageDetailButtonIconSize = px(32);

let imageCarouselScrollbarHeight = px(0);
let imageCarouselScrollbarBorderRadius = px(0);
let imageCarouselItemBorderRadius = px(4);
let imageCarouselItemMarginRight = `percent(2.);
let imageCarouselIndicatorSize = px(16);
let imageCarouselIndicatorBorderRadius = px(8);
let imageCarouselHMargin = px(4);