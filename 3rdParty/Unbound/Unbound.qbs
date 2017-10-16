import qbs

Product {
    name: "Unbound"
    //type: "staticlibrary"
    type: "dynamiclibrary"

    Depends {
        name: "cpp"
    }
    Depends {
        name: "Ldns"
    }
    cpp.includePaths: [".","src/unbound"]
    cpp.defines: []

    Properties {
        condition: qbs.targetOS.contains("android")
        cpp.includePaths: outer.concat([
            "src/android/compat",
            "src/android/config",
            "src/android/dns"
        ])
    }
    Properties {
        condition: product.type == "staticlibrary"
        cpp.defines: outer.concat(["UNBOUND_STATICLIB"])
    }
    
    Group {
        name: "source files"
        prefix: "src/"
        files: [
            "unbound/compat/ctime_r.c",
            "unbound/compat/gmtime_r.c",
            "unbound/compat/snprintf.c",
            "unbound/daemon/acl_list.c",
            "unbound/daemon/cachedump.c",
            "unbound/daemon/daemon.c",
            "unbound/daemon/remote.c",
            "unbound/daemon/stats.c",
            "unbound/daemon/unbound.c",
            // duplicate symbols: "unbound/daemon/worker.c",
            "unbound/iterator/iter_delegpt.c",
            "unbound/iterator/iter_donotq.c",
            "unbound/iterator/iter_fwd.c",
            "unbound/iterator/iter_hints.c",
            "unbound/iterator/iter_priv.c",
            "unbound/iterator/iter_resptype.c",
            "unbound/iterator/iter_scrub.c",
            "unbound/iterator/iter_utils.c",
            "unbound/iterator/iterator.c",
            "unbound/libunbound/context.c",
            "unbound/libunbound/libunbound.c",
            "unbound/libunbound/libworker.c",
            "unbound/services/cache/dns.c",
            "unbound/services/cache/infra.c",
            "unbound/services/cache/rrset.c",
            "unbound/services/listen_dnsport.c",
            "unbound/services/localzone.c",
            "unbound/services/mesh.c",
            "unbound/services/modstack.c",
            "unbound/services/outbound_list.c",
            "unbound/services/outside_network.c",
            "unbound/util/alloc.c",
            "unbound/util/config_file.c",
            "unbound/util/configlexer.c",
            "unbound/util/configparser.c",
            "unbound/util/data/dname.c",
            "unbound/util/data/msgencode.c",
            "unbound/util/data/msgparse.c",
            "unbound/util/data/msgreply.c",
            "unbound/util/data/packed_rrset.c",
            "unbound/util/fptr_wlist.c",
            "unbound/util/locks.c",
            "unbound/util/log.c",
            "unbound/util/mini_event.c",
            "unbound/util/module.c",
            "unbound/util/net_help.c",
            "unbound/util/netevent.c",
            "unbound/util/random.c",
            "unbound/util/rbtree.c",
            "unbound/util/regional.c",
            "unbound/util/rtt.c",
            "unbound/util/storage/dnstree.c",
            "unbound/util/storage/lookup3.c",
            "unbound/util/storage/lruhash.c",
            "unbound/util/storage/slabhash.c",
            "unbound/util/timehist.c",
            "unbound/util/tube.c",
            // unbound/util/winsock_event.c
            "unbound/validator/autotrust.c",
            "unbound/validator/val_anchor.c",
            "unbound/validator/val_kcache.c",
            "unbound/validator/val_kentry.c",
            "unbound/validator/val_neg.c",
            "unbound/validator/val_nsec.c",
            "unbound/validator/val_nsec3.c",
            "unbound/validator/val_secalgo.c",
            "unbound/validator/val_sigcrypt.c",
            "unbound/validator/val_utils.c",
            "unbound/validator/validator.c",
        ]
    }

    Export {
        Depends { name: "cpp" }
        cpp.defines: product.cpp.defines.concat(["HAVE_" + product.name.toUpperCase()])
        cpp.includePaths: [product.buildDirectory + "/" + product.name]
    }

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
    Group {
        qbs.install: true
        qbs.installDir: product.name
        fileTagsFilter: "hpp"
    }
}
